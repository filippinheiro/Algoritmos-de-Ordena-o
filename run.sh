#!/bin/bash

gcc ordena.c arquivo.c sort.c -o ordena
gcc arquivo.c gera.c -o gera

#modelo processador
cat /proc/cpuinfo | grep name | cut -c1- | cut -d : -f2 > resultado.txt
echo " " >> resultado.txt

ordem=("Crescente" "Decrescente" "Aleatório")
algoritimo=("bolha" "insercaoDireta" "binaria" "selecao" "shell" "heap" "quicksortini" "quicksortcentro" "quicksortmediana" "merge" "radix" "bucket")
arg=("-c" "-d" "-a")

echo "# Resultado ordenação! #\n" >> resultado.txt
echo "Tempo\tComparações\tTroca\t" >> resultado.txt
echo " " >> resultado.txt

for n in 100 1000 10000;
do
    for((i=0; i<3; i++));
    do
        echo "## Ordenar ${ordem[$i]} $n ##" >> resultado.txt
        ./gera ${arg[$i]} $n

        for((j=0; j<12; j++));
        do
            ./ordena ${algoritimo[$j]} $n entrada.txt >> resultado.txt
        done
        echo " " >> resultado.txt
    done
done