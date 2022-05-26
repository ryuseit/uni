#!/bin/csh -fx

mkdir bant2
./ircat -f 96000 -i baddn2/l03l.raw -o bant2/l03l.txt
./ircat -f 96000 -i baddn2/l03r.raw -o bant2/l03r.txt
./ircat -f 96000 -i baddn2/r03l.raw -o bant2/r03l.txt
./ircat -f 96000 -i baddn2/r03r.raw -o bant2/r03r.txt
mkdir baot2
./ircat -f 96000 -i baddo2/l03l.raw -o baot2/l03l.txt
./ircat -f 96000 -i baddo2/l03r.raw -o baot2/l03r.txt
./ircat -f 96000 -i baddo2/r03l.raw -o baot2/r03l.txt
./ircat -f 96000 -i baddo2/r03r.raw -o baot2/r03r.txt
mkdir bat2
./ircat -f 96000 -i bmdiv2/470l.raw -o bat2/470l.txt
./ircat -f 96000 -i bmdiv2/470r.raw -o bat2/470r.txt
./ircat -f 96000 -i bmdiv2/473l.raw -o bat2/473l.txt
./ircat -f 96000 -i bmdiv2/473r.raw -o bat2/473r.txt