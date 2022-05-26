#!/bin/csh -fx

#バイノーラル
set NUM1 = ( 087 088 094 095 099 100 105 106 107 114 116 121 122 128 129 136 137 )

mkdir bcut
mkdir b2cut
mkdir bctxt
mkdir b2ctxt

@ COUNT = 1
while ($COUNT <= $#NUM1)
#スタート位置から周波数×時間(s)で入力出力
./dcut -m 1 -s 0 -e 9600 -i bpal/p0${NUM1[$COUNT]}.1 -o bcut/c0${NUM1[$COUNT]}.1
./dcut -m 1 -s 0 -e 9600 -i bpal/p0${NUM1[$COUNT]}.2 -o bcut/c0${NUM1[$COUNT]}.2
./dcut -m 2 -s 0 -e 9600 -i bpal/p0${NUM1[$COUNT]}.raw -o b2cut/c20${NUM1[$COUNT]}.raw

./ircat -f 48000 -i bcut/c0${NUM1[$COUNT]}.1  -o bctxt/tc0${NUM1[$COUNT]}a.txt
./ircat -f 48000 -i bcut/c0${NUM1[$COUNT]}.2  -o bctxt/tc0${NUM1[$COUNT]}b.txt
./ircat -f 48000 -i b2cut/c20${NUM1[$COUNT]}.raw -o b2ctxt/tc0${NUM1[$COUNT]}.txt
@ COUNT++
end