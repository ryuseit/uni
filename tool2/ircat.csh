#!/bin/csh -fx
set EXE1 = ./ircat

#バイノーラル
set NUM1 = ( 087 088 094 095 099 100 105 106 107 114 116 121 122 128 129 136 137 )

#無指向性
set NUM2 =(089 090 091 092 093 103 104 111 112 118 119 124 125 132 133 134 135 )
mkdir btxt
mkdir gtxt
mkdir hiyomixpal

@ COUNT = 1
while ($COUNT <= $#NUM1)
#バイノーラル
./div -d -m 2 -i bpal/p0${NUM1[$COUNT]}.raw -o bpal/p0${NUM1[$COUNT]}
./div  -m 2 -i hiyodori48kmixpal/c0${NUM1[$COUNT]}h.raw -o hiyomixpal/c0${NUM1[$COUNT]}
./ircat -f 48000 -i bpal/p0${NUM1[$COUNT]}.1  -o btxt/t0${NUM1[$COUNT]}a.txt
./ircat -f 48000 -i bpal/p0${NUM1[$COUNT]}.2  -o btxt/t0${NUM1[$COUNT]}b.txt
#./ircat -f 48000 -i bpal/p0${NUM1[$COUNT]}.raw  -o btxt/t0${NUM1[$COUNT]}.txt
#無指向性
#./ircat -f 48000 -i .raw  -o .txt
./ircat -f 48000 -i gpal1/p0${NUM2[$COUNT]}.raw  -o gtxt1/t0${NUM2[$COUNT]}.txt
@ COUNT++
end