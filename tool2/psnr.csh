#!/bin/csh -fx

set NUM3 = ( 277 278 448 )
mkdir psnr
@ COUNT = 1
while ($COUNT <= $#NUM3)
./snr -l 72000 -1 imp/c0${NUM3[$COUNT]}l.raw -2 imp/c0${NUM3[$COUNT]}r.raw -o psnr/0${NUM3[$COUNT]}.txt
@ COUNT++
end