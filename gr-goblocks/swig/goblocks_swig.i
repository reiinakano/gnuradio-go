/* -*- c++ -*- */

#define GOBLOCKS_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "goblocks_swig_doc.i"

%{
#include "goblocks/qpsk_demod_cb.h"
%}


%include "goblocks/qpsk_demod_cb.h"
GR_SWIG_BLOCK_MAGIC2(goblocks, qpsk_demod_cb);
