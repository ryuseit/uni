#!/bin/csh -fx
set EXE1 = ./ircat

#バイノーラル
set NUM1 = ( 087 088 094 095 099 100 105 106 107 114 116 121 122 128 129 136 137 )

#無指向性
set NUM2 =(089 090 091 092 093 103 104 111 112 118 119 124 125 132 133 134 135 )
#出力フォルダを指定
mkdir hiyomixpal

@ COUNT = 1
while ($COUNT <= $#NUM1)
#2ch→1ch
#./div -d -m 2 -i  -o 
./div  -m 2 -i hiyodori48kmixpal/c0${NUM1[$COUNT]}h.raw -o hiyomixpal/c0${NUM1[$COUNT]}
@ COUNT++
end