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

#ifndef INCLUDED_BCHENCODER_BCHCLASS_H
#define INCLUDED_BCHENCODER_BCHCLASS_H

#include <bchencoder/api.h>
#include <stdint.h>
#include <stdio.h>

#define		  BCH15_5 	1
#define     BCH15_7 	2
#define     BCH15_11 	3
#define     BCH31_6		4
#define     BCH31_11	5
#define     BCH63_7		6
#define     BCH63_10	7

namespace gr {
  namespace bchencoder {

    /*!
     * \brief <+description+>
     *
     */
    class BCHENCODER_API bchclass
    {
    public:
      int m, n, length, k, t, d;
      bchclass(int type);
      ~bchclass();

      void encode_bch( uint8_t datai[],uint8_t datao[]);


	    int decode_bch( uint8_t datai[],uint8_t datao[]);
    private:

      int p[21];
      int alpha_to[1048576], index_of[1048576], g[548576];
      int recd[1048576], data[1048576], bb[548576];

      void generate_gf();
      /*
        * Generate field GF(2**m) from the irreducible polynomial p(X) with
        * coefficients in p[0]..p[m].
        *
        * Lookup tables:
        *   index->polynomial form: alpha_to[] contains j=alpha^i;
        *   polynomial form -> index form:     index_of[j=alpha^i] = i
        *
        * alpha=2 is the primitive element of GF(2**m)
        */


      void gen_poly();
      /*
        * Compute the generator polynomial of a binary BCH code. Fist generate the
        *   cycle sets modulo 2**m - 1, cycle[][] =  (i, 2*i, 4*i, ..., 2^l*i). Then
        *   determine those cycle sets that contain integers in the set of (d-1)
        *   consecutive integers {1..(d-1)}. The generator polynomial is calculated
        *   as the product of linear factors of the form (x+alpha^i), for every i in
        *   the above cycle sets.
        */

    };

  } // namespace bchencoder
} // namespace gr

#endif /* INCLUDED_BCHENCODER_BCHCLASS_H */

