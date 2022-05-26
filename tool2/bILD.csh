#!/bin/csh -fx
gcc -Wl,--stack,10485760 -o ILD ILD.c -lm



mkdir bild
 foreach f(bgdiv/*.1)
./ILD bgdiv/$f:t:r.1 bgdiv/$f:t:r.2 bild/$f:t:r.txt
 end

mkdir pbild
 foreach f(pbmdiv/*.1)
./ILD pbmdiv/$f:t:r.1 pbmdiv/$f:t:r.2 pbild/$f:t:r.txt
 end