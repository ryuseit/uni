#!/bin/csh -fx
set EXE1 = ./tspconv

#バイノーラル
set NUM1 = ( 461 462 463 464 465 466 467 468 469 470 471 472 473 474 475)
#無指向性
set NUM2 =( 452 453 454 455 456 457 458 459 460 476 477 478 )
@ COUNT = 1
mkdir bdiv2
mkdir btxt2
mkdir gtxt2
mkdir bcut2
mkdir gcut2
while ($COUNT <= $#NUM1)
#バイノーラル
./dcut -m 2 -s 0 -e 19200 -i bpal2/p0${NUM1[$COUNT]}.raw -o bcut2/c0${NUM1[$COUNT]}.raw
./div  -m 2 -d -i bcut2/c0${NUM1[$COUNT]}.raw -o bdiv2/c0${NUM1[$COUNT]}
./ircat -f 96000 -i bdiv2/c0${NUM1[$COUNT]}.1  -o btxt2/t0${NUM1[$COUNT]}a.txt
./ircat -f 96000 -i bdiv2/c0${NUM1[$COUNT]}.2  -o btxt2/t0${NUM1[$COUNT]}b.txt
@ COUNT++
end

@ COUNTA = 1
while ($COUNTA <= $#NUM2)
#無指向性
./dcut -m 1 -s 0 -e 19200 -i gpal2/p0${NUM2[$COUNTA]}.raw -o gcut2/c0${NUM2[$COUNTA]}.raw
./ircat -f 96000 -i gcut2/c0${NUM2[$COUNTA]}.raw -o gtxt2/t0${NUM2[$COUNTA]}.txt
@ COUNTA++
end
