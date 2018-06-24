/* -*- c++ -*- */
/* 
 * Copyright 2018 gr-goblocks author.
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
#include "qpsk_demod_cb_impl.h"

#include "libgo_qpsk_demod_cb.h"

namespace gr {
  namespace goblocks {

    qpsk_demod_cb::sptr
    qpsk_demod_cb::make(bool gray_code)
    {
      return gnuradio::get_initial_sptr
        (new qpsk_demod_cb_impl(gray_code));
    }

    /*
     * The private constructor
     */
    qpsk_demod_cb_impl::qpsk_demod_cb_impl(bool gray_code)
      : gr::sync_block("qpsk_demod_cb",
              gr::io_signature::make(1, 1, sizeof(float)),
              gr::io_signature::make(1, 1, sizeof(char)))
    {
      // CODE AUTOGENERATED BY GO-GNURADIO. DO NOT EDIT.
      set_output_multiple_ptr_ = new std::function<void(int)>(boost::bind(&qpsk_demod_cb_impl::set_output_multiple, this, _1));
      history_ptr_ = new std::function<unsigned int()>(boost::bind(&qpsk_demod_cb_impl::history, this));
      __go_gnuradio_index = QpskDemodCbGoGRInit(
        reinterpret_cast<unsigned long long>(set_output_multiple_ptr_),
        reinterpret_cast<unsigned long long>(history_ptr_)
      );
      // CODE AUTOGENERATED BY GO-GNURADIO. DO NOT EDIT.

      // Your connection between C++ and Go. Modify this function to pass in block variables.
      // Don't forget to modify the equivalent in Go code!
      QpskDemodCbInit(__go_gnuradio_index, gray_code); 
    }

    /*
     * Our virtual destructor.
     */
    qpsk_demod_cb_impl::~qpsk_demod_cb_impl()
    {
      delete set_output_multiple_ptr_;
      QpskDemodCbDelete(__go_gnuradio_index);
    }

    int
    qpsk_demod_cb_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      float *in = (float *) input_items[0];
      unsigned char *out = (unsigned char *) output_items[0];

      GoSlice go_in = {in, noutput_items, noutput_items};
      GoSlice go_out = {out, noutput_items, noutput_items};

      return QpskDemodCbWork(go_in, go_out, __go_gnuradio_index);
    }

  } /* namespace goblocks */
} /* namespace gr */

