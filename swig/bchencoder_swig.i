/* -*- c++ -*- */

#define BCHENCODER_API

%include "gnuradio.i"           // the common stuff

//load generated python docstrings
%include "bchencoder_swig_doc.i"

%{
#include "bchencoder/bchencoder_bb.h"
%}

%include "bchencoder/bchencoder_bb.h"
GR_SWIG_BLOCK_MAGIC2(bchencoder, bchencoder_bb);
