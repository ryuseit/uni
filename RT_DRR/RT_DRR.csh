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
foreach filename ( ${IN}/*.raw )

#例： ./プログラム.exe 入力インパルス応答.raw 残響曲線.txt 残響時間・直間比情報.txt
$EXE ${filename} ${RCV}/${filename:t:r}.txt ${TDRR}/test.txt

#残響曲線の出力
gnuplot <<EOF

set terminal png font "Times New Roman,20"
set output "${RCV}/${filename:t:r}.png"
set xlabel "Time[sec]"
set ylabel "Gain[dB]"
set xrange [0:2.0]
#set yrange [-70:0]
plot "${RCV}/${filename:t:r}.txt" with lines not

EOF

rm ${RCV}/${filename:t:r}.txt

end