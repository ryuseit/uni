#!/bin/csh -fx
#残響時間と直間比を算出するシェル

set IN = ./1_Input
set RCV = ./2_R-curve_png
set TDRR = ./3_RT_DRR

set EXE = ./Program/RT_DRR.exe

echo "RUN : RT_DRR.csh"

gcc -o ./Program/RT_DRR ./Program/RT_DRR.c

rm ${RCV}/*
rm ${TDRR}/*

#RUN
#foreach filename ( ${IN}/*.raw )
foreach filename ( ${IN}/* )
#例: ./プログラム.exe 入力インパルス応答.raw 残響曲線.txt 残響時間直間比情報.txt
$EXE ${filename} ${RCV}/${filename:t:r}.txt ${TDRR}/${filename:t:r}.txt

end