#!/bin/csh -fx

mkdir pdiv

foreach f(prawb/*.raw)
./div  -m 2 -i $f -o pdiv/$f:t:r
end