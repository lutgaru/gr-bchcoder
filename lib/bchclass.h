/*
 * bchclass.h
 *
 *  Created on: 25 jun. 2020
 *      Author: neft
 */
#include <stdint.h>
#include <stdio.h>

#ifndef BCHCLASS_H_
#define BCHCLASS_H_

enum bch_type{ BCHNONE,
        BCH15_5,
        BCH15_7,
        BCH15_11,
        BCH31_6,
        BCH31_11,
        BCH63_7,
        BCH63_10,
        GOLAY23_12,};

class bchclass {
public:
	int m, n, length, k, t, d;
	bchclass(bch_type type);
	virtual ~bchclass();

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

#endif /* BCHCLASS_H_ */
