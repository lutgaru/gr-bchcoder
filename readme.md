**BCH encoder and decoder blocks for gnuradio**

Author: lutgaru

is a BCH encoder and decoder blocks for gnuradio, it is based in part on the project http://www.rajivchakravorty.com/source-code/uncertainty/multimedia-sim/html/index.html

and the File: bch3.c from book  Encoder/decoder for binary BCH codes in C (Version 3.1) from Author:  Robert Morelos-Zaragoza (robert@spectra.eng.hawaii.edu) August 1994


**example of use**

![alt text](https://i.imgur.com/HRznUw4.png)

**installation instructions**

clone repository 

`git clone https://gitlab.com/lutgaru/gr-bchcoder.git`

access to dir

`cd gr-bchcoder`

create a build directory

- `mkdir build`
- `cd build`

make a project

- `cmake ../`
- `make`

install module

`sudo make install`

call a ldconfig

`sudo ldconfig`

if the block cannot be accessed you can try the following


make a radiooutoftree.conf in /etc/ld.so.conf.d/

`sudo nano /etc/ld.so.conf.d/radiooutoftree.conf`

and add into `/usr/local/lib`
