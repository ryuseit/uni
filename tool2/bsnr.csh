#!/bin/csh -fx
#バイノーラル
set NUM1 = ( 461 462 463 464 465 466 470 472 473 474 475 )

mkdir bsnr
@ COUNT = 1
while ($COUNT <= $#NUM1)
./snr -l 72000 -1 dbpal2/db0${NUM1[$COUNT]}l.raw -2 dbpal2/db0${NUM1[$COUNT]}r.raw -o bsnr/b0${NUM1[$COUNT]}.txt

@ COUNT++
end