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
    bchencoder_bb::make(bch_type bchtype)
    {
      return gnuradio::get_initial_sptr
        (new bchencoder_bb_impl(bchtype));
    }


    /*
     * The private constructor
     */
    bchencoder_bb_impl::bchencoder_bb_impl(bch_type bchtype)
      : gr::block("bchencoder_bb",
              gr::io_signature::make(1, 1, sizeof(unsigned char)),
              gr::io_signature::make(1, 1, sizeof(unsigned char))),
            //mybchtype(bchtype)
    {
      bch=new bchclass(bchtype);
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
      ninput_items_required[0] = noutput_items*(bch->k/bch->length);
    }

    int
    bchencoder_bb_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      
      const unsigned char *in = (const unsigned char *) input_items[0];
      unsigned char *out = (unsigned char *) output_items[0];

      // Do <+signal processing+>

      int blks = std::min(noutput_items / bch->length, ninput_items[0] / bch->k);

      for (int i = 0; i < blks; i++) {
        
      }
      // Tell runtime system how many input items we consumed on
      // each input stream.
      consume_each (blks*bch->k);


      // Tell runtime system how many output items we produced.
      return blks*bch->length;
    }

  } /* namespace bchencoder */
} /* namespace gr */

