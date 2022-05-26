#!/bin/csh -fx
mkdir pirc
 foreach f(pgmdiv/*.raw)
./ircat -f 96000 -i $f -o pirc/$f:t:r.txt
end