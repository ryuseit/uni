#!/bin/csh -fx
gcc -Wl,--stack,10485760 -o ILD ILD.c -lm


set setf = bcmadd
set out = bcmild
 mkdir ${out}
 foreach f(${setf}/*.1)
./ILD ${setf}/$f:t:r.1 ${setf}/$f:t:r.2 ${out}/$f:t:r.txt
 end

set setf2 = bpmadd
set out2 = bpmild
 mkdir ${out2}
 foreach f(${setf2}/*.1)
./ILD ${setf2}/$f:t:r.1 ${setf2}/$f:t:r.2 ${out2}/$f:t:r.txt
 end