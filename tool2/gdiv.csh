#!/bin/csh -fx

mkdir gdiv

foreach f(grawb/*.raw)
#foreach f(bg10bai/*.raw)
./div  -m 2 -i $f -o gdiv/$f:t:r -d
end