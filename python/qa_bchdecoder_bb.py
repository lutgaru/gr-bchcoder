#!/usr/bin/env python
# -*- coding: utf-8 -*-
#                     GNU GENERAL PUBLIC LICENSE
#                        Version 3, 29 June 2007
#
#  Copyright (C) 2007 Free Software Foundation, Inc. <http://fsf.org/>
#  Everyone is permitted to copy and distribute verbatim copies
#  of this license document, but changing it is not allowed.
#
#

from gnuradio import gr, gr_unittest
from gnuradio import blocks
import bchencoder_swig as bchencoder

class qa_bchdecoder_bb(gr_unittest.TestCase):

    def setUp(self):
        self.tb = gr.top_block()

    def tearDown(self):
        self.tb = None

    def test_001_t(self):
        # set up fg
        src_data=(0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0)
        expected_result=(0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0)
        src = blocks.vector_source_b(src_data)
        encod= bchencoder.bchdecoder_bb(3)
        dst = blocks.vector_sink_b()
        self.tb.connect(src, encod)
        self.tb.connect(encod, dst)
        self.tb.run()
        result_data = dst.data()
        self.assertTupleEqual(expected_result, result_data)
        # check data


if __name__ == '__main__':
    gr_unittest.run(qa_bchdecoder_bb)
