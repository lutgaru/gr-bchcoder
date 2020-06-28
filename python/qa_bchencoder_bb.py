#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright 2020 gr-bchencoder author.
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
import bchencoder_swig as bchencoder
import time

class qa_bchencoder_bb(gr_unittest.TestCase):

    def setUp(self):
        self.tb = gr.top_block()

    def tearDown(self):
        self.tb = None

    def test_001_bchencoder_bb(self):
        src_data=(0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0)
        expected_result=(0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0)
        src = blocks.vector_source_b(src_data)
        #contrl= blocks.throttle(gr.sizeof_char*1,10)
        encod= bchencoder.bchencoder_bb(3)
        dst = blocks.vector_sink_b()
        #print("conectando")
        self.tb.connect(src, encod)
        #self.tb.connect(contrl, encod)
        self.tb.connect(encod, dst)
        # set up fg
        #print("inicio")
        self.tb.run()
        #self.tb.start()
        #time.sleep(0.1)
        #self.tb.stop()
        #self.tb.wait()
        # check data
        result_data = dst.data()
        #print(src_data)
        #print(result_data)
        self.assertTupleEqual(expected_result, result_data)
        #self.assertEqual(len(result_data),len(expected_result))

    def test_002_bchencoder_bb(self):
        src_data=(0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0)
        expected_result=(0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0)
        src = blocks.vector_source_b(src_data)
        encod= bchencoder.bchencoder_bb(3)
        dst = blocks.vector_sink_b()
        print("conectando")
        self.tb.connect(src, encod)
        self.tb.connect(encod, dst)
        # set up fg
        print("inicio")
        self.tb.run()
        result_data = dst.data()
        print(src_data)
        print(result_data)
        self.assertTupleEqual(expected_result, result_data)
        #self.assertEqual(len(result_data),len(expected_result))


if __name__ == '__main__':
    gr_unittest.run(qa_bchencoder_bb)
