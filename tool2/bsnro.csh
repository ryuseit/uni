#!/bin/csh -fx


set ple = ( "r2" "c14" "l2" "r1" "c1" "l1" "r03" "c03" "l03" "l0" "r0" )

mkdir obsnr
@ COUNT = 1
while ($COUNT <= $#ple)
./snr -l 72000 -1 baddo/${ple[$COUNT]}l.raw -2 baddo/${ple[$COUNT]}r.raw -o obsnr/${ple[$COUNT]}.txt

@ COUNT++
end