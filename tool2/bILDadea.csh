#!/bin/csh -fx
gcc -Wl,--stack,10485760 -o ILDe ILDearly.c -lm


mkdir bildadd
 foreach f(bpmadd/*.1)
./ILDe bpmadd/$f:t:r.1 bpmadd/$f:t:r.2 bildadd/$f:t:r.txt
 end