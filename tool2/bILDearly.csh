#!/bin/csh -fx
gcc -Wl,--stack,10485760 -o ILDe ILDearly.c -lm



mkdir bilde
 foreach f(bgdiv/*.1)
./ILDe bgdiv/$f:t:r.1 bgdiv/$f:t:r.2 bilde/$f:t:r.txt
 end

mkdir pbilde
 foreach f(pbmdiv/*.1)
./ILDe pbmdiv/$f:t:r.1 pbmdiv/$f:t:r.2 pbilde/$f:t:r.txt
 end