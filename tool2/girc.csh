#!/bin/csh -fx
mkdir girc
 foreach f(gmdiv/*.raw)
./ircat -f 96000 -i $f -o girc/$f:t:r.txt
end