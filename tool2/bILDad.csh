#!/bin/csh -fx
gcc -Wl,--stack,10485760 -o ILD ILD.c -lm


mkdir bildadd
 foreach f(bpmadd/*.1)
./ILD bpmadd/$f:t:r.1 bpmadd/$f:t:r.2 bildadd/$f:t:r.txt
 end

 mkdir bildadd01a
 foreach f(bpmadd01a/*.1)
./ILD bpmadd01a/$f:t:r.1 bpmadd01a/$f:t:r.2 bildadd01a/$f:t:r.txt
 end

  mkdir bildadd01b
 foreach f(bpmadd01b/*.1)
./ILD bpmadd01b/$f:t:r.1 bpmadd01b/$f:t:r.2 bildadd01b/$f:t:r.txt
 end