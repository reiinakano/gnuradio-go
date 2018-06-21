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


#ifndef INCLUDED_GOBLOCKS_QPSK_DEMOD_CB_H
#define INCLUDED_GOBLOCKS_QPSK_DEMOD_CB_H

#include <goblocks/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace goblocks {

    /*!
     * \brief <+description of block+>
     * \ingroup goblocks
     *
     */
    class GOBLOCKS_API qpsk_demod_cb : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<qpsk_demod_cb> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of goblocks::qpsk_demod_cb.
       *
       * To avoid accidental use of raw pointers, goblocks::qpsk_demod_cb's
       * constructor is in a private implementation
       * class. goblocks::qpsk_demod_cb::make is the public interface for
       * creating new instances.
       */
      static sptr make(bool gray_code);
    };

  } // namespace goblocks
} // namespace gr

#endif /* INCLUDED_GOBLOCKS_QPSK_DEMOD_CB_H */

