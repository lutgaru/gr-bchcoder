/* -*- c++ -*- */
/*                     GNU GENERAL PUBLIC LICENSE
 *                        Version 3, 29 June 2007
 *
 *  Copyright (C) 2007 Free Software Foundation, Inc. <http://fsf.org/>
 *  Everyone is permitted to copy and distribute verbatim copies
 *  of this license document, but changing it is not allowed.
 *
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "bchdecoder_bb_impl.h"

namespace gr {
  namespace bchencoder {

    bchdecoder_bb::sptr
    bchdecoder_bb::make(int bchtype)
    {
      return gnuradio::get_initial_sptr
        (new bchdecoder_bb_impl(bchtype));
    }


    /*
     * The private constructor
     */
    bchdecoder_bb_impl::bchdecoder_bb_impl(int bchtype)
      : gr::block("bchdecoder_bb",
              gr::io_signature::make(1, 1, sizeof(unsigned char)),
              gr::io_signature::make(1, 1, sizeof(unsigned char)))
    {
      bch=new bchclass(bchtype);
      printf("construido");
      set_output_multiple(bch->k);
    }

    /*
     * Our virtual destructor.
     */
    bchdecoder_bb_impl::~bchdecoder_bb_impl()
    {
    }

    void
    bchdecoder_bb_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      /* <+forecast+> e.g. ninput_items_required[0] = noutput_items */
      ninput_items_required[0] = (noutput_items*bch->length)/bch->k;
    }

    int
    bchdecoder_bb_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const unsigned char *in = (const unsigned char *) input_items[0];
      unsigned char *out = (unsigned char *) output_items[0];
      uint8_t blockinput[bch->length];
      uint8_t blockoutput[bch->k];

      // Do <+signal processing+>

      int blks = std::min(noutput_items / bch->k, ninput_items[0] / bch->length);
      printf("blocks: %d\n",blks);

      for (int i = 0; i < blks; i++) {
          for(int j=0;j < bch->length;j++){
            blockinput[j]=in[j+(i*bch->length)];
          }
          bch->decode_bch(blockinput,blockoutput);
          for(int j=0;j < bch->k;j++){
            out[j+(i*bch->k)]=blockoutput[j];
          }
      }
      // Tell runtime system how many input items we consumed on
      // each input stream.
      consume_each (blks*bch->length);

      // Tell runtime system how many output items we produced.
      return blks*bch->k;
    }

  } /* namespace bchencoder */
} /* namespace gr */

