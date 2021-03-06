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
              gr::io_signature::make(1, 1, sizeof(gr_complex)),
              gr::io_signature::make(1, 1, sizeof(char)))
    {
      // CODE AUTOGENERATED BY GO-GNURADIO. DO NOT EDIT.
      output_multiple_ptr_ = new std::function<int()>(boost::bind(&qpsk_demod_cb_impl::output_multiple, this));
      set_output_multiple_ptr_ = new std::function<void(int)>(boost::bind(&qpsk_demod_cb_impl::set_output_multiple, this, _1));
      history_ptr_ = new std::function<unsigned int()>(boost::bind(&qpsk_demod_cb_impl::history, this));
      set_history_ptr_ = new std::function<void(unsigned int)>(boost::bind(&qpsk_demod_cb_impl::set_history, this, _1));
      alignment_ptr_ = new std::function<int()>(boost::bind(&qpsk_demod_cb_impl::alignment, this));
      set_alignment_ptr_ = new std::function<void(int)>(boost::bind(&qpsk_demod_cb_impl::set_alignment, this, _1));
      consume_each_ptr_ = new std::function<void(int)>(boost::bind(&qpsk_demod_cb::consume_each, this, _1));
      consume_ptr_ = new std::function<void(int, int)>(boost::bind(&qpsk_demod_cb::consume, this, _1, _2));
      produce_ptr_ = new std::function<void(int, int)>(boost::bind(&qpsk_demod_cb::produce, this, _1, _2));
      __go_gnuradio_index = QpskDemodCbGoGRInit(
        reinterpret_cast<unsigned long long>(output_multiple_ptr_),
        reinterpret_cast<unsigned long long>(set_output_multiple_ptr_),
        reinterpret_cast<unsigned long long>(history_ptr_),
        reinterpret_cast<unsigned long long>(set_history_ptr_),
        reinterpret_cast<unsigned long long>(alignment_ptr_),
        reinterpret_cast<unsigned long long>(set_alignment_ptr_),
        reinterpret_cast<unsigned long long>(consume_each_ptr_),
        reinterpret_cast<unsigned long long>(consume_ptr_),
        reinterpret_cast<unsigned long long>(produce_ptr_)
      );
      // END OF CODE AUTOGENERATED BY GO-GNURADIO.

      // Your connection between C++ and Go. Modify this function to pass in block variables.
      // Don't forget to modify the equivalent in Go code!
      QpskDemodCbInit(__go_gnuradio_index, gray_code); 
    }

    /*
     * Our virtual destructor.
     */
    qpsk_demod_cb_impl::~qpsk_demod_cb_impl()
    {
      // CODE AUTOGENERATED BY GO-GNURADIO. DO NOT EDIT.
      delete set_output_multiple_ptr_;
      delete history_ptr_;
      delete set_history_ptr_;
      delete alignment_ptr_;
      delete set_alignment_ptr_;
      delete consume_each_ptr_;
      delete consume_ptr_;
      delete produce_ptr_;
      QpskDemodCbDelete(__go_gnuradio_index);
     // END OF CODE AUTOGENERATED BY GO-GNURADIO.
    }

    int
    qpsk_demod_cb_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      gr_complex *in = (gr_complex *) input_items[0];
      unsigned char *out = (unsigned char *) output_items[0];

      GoSlice go_in = {in, noutput_items, noutput_items};
      GoSlice go_out = {out, noutput_items, noutput_items};

      return QpskDemodCbWork(go_in, go_out, __go_gnuradio_index);
    }

    bool qpsk_demod_cb_impl::start() {
      return QpskDemodCbStart(__go_gnuradio_index);
    }

    bool qpsk_demod_cb_impl::stop() {
      return QpskDemodCbStop(__go_gnuradio_index);
    }

  } /* namespace goblocks */
} /* namespace gr */

