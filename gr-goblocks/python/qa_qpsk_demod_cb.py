#!/usr/bin/env python
# -*- coding: utf-8 -*-
# 
# Copyright 2018 gr-goblocks author.
# 
# This is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
# 
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this software; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.
# 

from gnuradio import gr, gr_unittest
from gnuradio import blocks
import goblocks_swig as goblocks
from numpy import array

class qa_qpsk_demod_cb (gr_unittest.TestCase):

    def setUp (self):
        self.tb = gr.top_block ()

    def tearDown (self):
        self.tb = None

    def test_001_gray_code_enabled (self):
        # "Construct the Iphase and Qphase components"
        src_data = array([ 12.3, 23.2, 1, 0])
        # "Enable Gray code"
        gray_code =  True
        # "Determine the expected result"
        expected_result = (12, 23, 1, 0)
        # "Create a complex vector source"
        src = blocks.vector_source_f(src_data)
        # "Instantiate the test module"
        qpsk_demod = goblocks.qpsk_demod_cb(gray_code)
        # "Instantiate the binary sink"
        dst = blocks.vector_sink_b()
        # "Construct the flowgraph"
        self.tb.connect(src,qpsk_demod)
        self.tb.connect(qpsk_demod,dst)
        # "Create the flow graph"
        self.tb.run ()
        # check data
        result_data = dst.data()
        self.assertTupleEqual(expected_result, result_data)
        self.assertEqual(len(expected_result), len(result_data))

    def test_002_gray_code_disabled (self):
        # "Construct the Iphase and Qphase components"
        src_data = array([ 0, 0.2, 0.5, 1])
        # "Disable Gray code"
        gray_code =  False
        # "Determine the expected result"
        expected_result = (0, 51, 127, 255)
        # "Create a complex vector source"
        src = blocks.vector_source_f(src_data)
        # "Instantiate the test module"
        qpsk_demod = goblocks.qpsk_demod_cb(gray_code)
        # "Instantiate the binary sink"
        dst = blocks.vector_sink_b()
        # "Construct the flowgraph"
        self.tb.connect(src,qpsk_demod)
        self.tb.connect(qpsk_demod,dst)
        # "Create the flow graph"
        self.tb.run ()
        # check data
        result_data = dst.data()
        self.assertTupleEqual(expected_result, result_data)
        self.assertEqual(len(expected_result), len(result_data))


if __name__ == '__main__':
    gr_unittest.run(qa_qpsk_demod_cb, "qa_qpsk_demod_cb.xml")
