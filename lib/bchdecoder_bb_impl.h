/* -*- c++ -*- */
/*                     GNU GENERAL PUBLIC LICENSE
 *                        Version 3, 29 June 2007
 *
 */

#ifndef INCLUDED_BCHENCODER_BCHDECODER_BB_IMPL_H
#define INCLUDED_BCHENCODER_BCHDECODER_BB_IMPL_H

#include <bchencoder/bchdecoder_bb.h>
#include <bchencoder/bchclass.h>

namespace gr {
  namespace bchencoder {

    class bchdecoder_bb_impl : public bchdecoder_bb
    {
     private:
      // Nothing to declare in this block.
      bchclass *bch;

     public:
      bchdecoder_bb_impl(int bchtype);
      ~bchdecoder_bb_impl();

      // Where all the action really happens
      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
           gr_vector_int &ninput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);

    };

  } // namespace bchencoder
} // namespace gr

#endif /* INCLUDED_BCHENCODER_BCHDECODER_BB_IMPL_H */

