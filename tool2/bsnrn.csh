#!/bin/csh -fx

set ple = ( "r2" "c14" "l2" "r1" "c1" "l1" "r03" "c03" "l03" "l0" "r0" )

mkdir nbsnr
@ COUNT = 1
while ($COUNT <= $#ple)
./snr -l 72000 -1 baddn/${ple[$COUNT]}l.raw -2 baddn/${ple[$COUNT]}r.raw -o nbsnr/${ple[$COUNT]}.txt

@ COUNT++
end