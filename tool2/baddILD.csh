#!/bin/csh -fx
gcc -Wl,--stack,10485760 -o ILD ILD.c -lm

  mkdir baddildold
 foreach f(bpaddold/*.1)
./ILD bpaddold/$f:t:r.1 bpaddold/$f:t:r.2 baddildold/$f:t:r.txt
 end

 mkdir pbaddild
 foreach f(bpadd/*.1)
./ILD bpadd/$f:t:r.1 bpadd/$f:t:r.2 pbaddild/$f:t:r.txt
 end
