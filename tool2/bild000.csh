#!/bin/csh -fx
gcc -Wl,--stack,10485760 -o ILD ILD.c -lm

mkdir bild
 foreach f(bgdiv/*.1)
./snr -l 48000 -1 bgdiv/$f:t:r.1 -2 bgdiv/$f:t:r.2 -o bild/$f:t:r.txt
 end

mkdir pbild
 foreach f(pbmdiv/*.1)
./snr -l 19200 -1 pbmdiv/$f:t:r.1 -2 pbmdiv/$f:t:r.2 -o pbild/$f:t:r.txt
 end