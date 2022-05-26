#!/bin/csh -fx

mkdir bgdiv

foreach f(bgmdiv/*.raw)
#foreach f(bg10bai/*.raw)
./div  -m 2 -i $f -o bgdiv/$f:t:r -d
end