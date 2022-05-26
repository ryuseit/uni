#!/bin/csh -fx
mkdir ptxt

foreach f(pmdiv/*.raw)
./ircat -f 96000 -i $f -o ptxt/t$f:t:r.txt
end
