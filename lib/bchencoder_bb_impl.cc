/* -*- c++ -*- */
/*
 * Copyright 2020 gr-bchencoder author.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "bchencoder_bb_impl.h"


namespace gr {
  namespace bchencoder {

    bchencoder_bb::sptr
    bchencoder_bb::make(int bchtype)
    {
      return gnuradio::get_initial_sptr
        (new bchencoder_bb_impl(bchtype));
    }


    /*
     * The private constructor
     */
    bchencoder_bb_impl::bchencoder_bb_impl(int bchtype)
      : gr::block("bchencoder_bb",
              gr::io_signature::make(1, 1, sizeof(unsigned char)),
              gr::io_signature::make(1, 1, sizeof(unsigned char)))
            //mybchtype(bchtype)
    {
      /* switch (bchtype)
      {
      case 1:
        mybchtype=bch_type::BCH15_5;
        break;
      case 2:
        mybchtype=bch_type::BCH15_7;
        break;
      case 3:
        mybchtype=bch_type::BCH15_11;
        break;
      case 4:
        mybchtype=bch_type::BCH31_6;
        break;
      case 5:
        mybchtype=bch_type::BCH31_11;
        break;
      case 6:
        mybchtype=bch_type::BCH63_7;
        break;
      case 7:
        mybchtype=bch_type::BCH63_10;
        break;
      default:
        break;
      } */

      bch=new bchclass(bchtype);
      //printf("construido");
      set_output_multiple(bch->length);
    }

    /*
     * Our virtual destructor.
     */
    bchencoder_bb_impl::~bchencoder_bb_impl()
    {
    }

    void
    bchencoder_bb_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      /* <+forecast+> e.g. ninput_items_required[0] = noutput_items */
      ninput_items_required[0] = (noutput_items*bch->k)/bch->length;
      
      //printf("input req: %d outputs:%d\n",ninput_items_required[0],noutput_items);
      //printf("len: %d k:%d\n",bch->length,bch->k);
      
      
    }

    int
    bchencoder_bb_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      
      const unsigned char *in = (const unsigned char *) input_items[0];
      unsigned char *out = (unsigned char *) output_items[0];
      uint8_t blockinput[bch->k];
      uint8_t blockoutput[bch->length];
      // Do <+signal processing+>

      int blks = std::min(noutput_items / bch->length, ninput_items[0] / bch->k);
      printf("blocks: %d\n",blks);

      for (int i = 0; i < blks; i++) {
          for(int j=0;j < bch->k;j++){
            blockinput[j]=in[j+(i*bch->k)];
          }
          bch->encode_bch(blockinput,blockoutput);
          for(int j=0;j < bch->length;j++){
            out[j+(i*bch->length)]=blockoutput[j];
          }
      }
      // Tell runtime system how many input items we consumed on
      // each input stream.
      consume_each (blks*bch->k);


      // Tell runtime system how many output items we produced.
      return blks*bch->length;
    }

  } /* namespace bchencoder */
} /* namespace gr */

