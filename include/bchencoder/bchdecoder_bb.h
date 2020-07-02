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


#ifndef INCLUDED_BCHENCODER_BCHDECODER_BB_H
#define INCLUDED_BCHENCODER_BCHDECODER_BB_H

#include <bchencoder/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace bchencoder {

    /*!
     * \brief <+description of block+>
     * \ingroup bchencoder
     *
     */
    class BCHENCODER_API bchdecoder_bb : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<bchdecoder_bb> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of bchencoder::bchdecoder_bb.
       *
       * To avoid accidental use of raw pointers, bchencoder::bchdecoder_bb's
       * constructor is in a private implementation
       * class. bchencoder::bchdecoder_bb::make is the public interface for
       * creating new instances.
       */
      static sptr make(int bchtype);
    };

  } // namespace bchencoder
} // namespace gr

#endif /* INCLUDED_BCHENCODER_BCHDECODER_BB_H */

