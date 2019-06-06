gcc ordena.c arquivo.c ordenacao.c -o ordena
gcc arquivo.c gera.c -o gera

n=100
max=10000
echo "# Resultado ordenação! #\n" > resultado.txt
echo "Tempo\tComparações\tTroca\tAlgoritimo" >> resultado.txt
while [ $n -le $max ];
do
    ./gera -c $n
    echo "\n =#=#=# Ordenar crescente $n =#=#=#" >> resultado.txt
    
    ./ordena bolha $n entrada.txt >> resultado.txt
    ./ordena insercaoDireta $n entrada.txt >> resultado.txt
    ./ordena binaria $n entrada.txt >> resultado.txt
    ./ordena selecao $n entrada.txt >> resultado.txt
    ./ordena shell $n entrada.txt >> resultado.txt
    ./ordena heap $n entrada.txt >> resultado.txt
    ./ordena quicksortini $n entrada.txt >> resultado.txt
    ./ordena quicksortcentro $n entrada.txt >> resultado.txt
    ./ordena quicksortmediana $n entrada.txt >> resultado.txt
    ./ordena merge $n entrada.txt >> resultado.txt
    ./ordena radix $n entrada.txt >> resultado.txt
    ./ordena bucket $n entrada.txt >> resultado.txt
    n=$((n*10))
done

n=100
while [ $n -le $max ];
do
    ./gera -d $n
    echo "\n =#=#=# Ordenar decrescente $n =#=#=#" >> resultado.txt
    
    ./ordena bolha $n entrada.txt >> resultado.txt
    ./ordena insercaoDireta $n entrada.txt >> resultado.txt
    ./ordena binaria $n entrada.txt >> resultado.txt
    ./ordena selecao $n entrada.txt >> resultado.txt
    ./ordena shell $n entrada.txt >> resultado.txt
    ./ordena heap $n entrada.txt >> resultado.txt
    ./ordena quicksortini $n entrada.txt >> resultado.txt
    ./ordena quicksortcentro $n entrada.txt >> resultado.txt
    ./ordena quicksortmediana $n entrada.txt >> resultado.txt
    ./ordena merge $n entrada.txt >> resultado.txt
    ./ordena radix $n entrada.txt >> resultado.txt
    ./ordena bucket $n entrada.txt >> resultado.txt
    n=$((n*10))
done

n=100
while [ $n -le $max ];
do
    ./gera -a $n
    echo "\n =#=#=# Ordenar aleatório $n =#=#=#" >> resultado.txt
    
    ./ordena bolha $n entrada.txt >> resultado.txt
    ./ordena insercaoDireta $n entrada.txt >> resultado.txt
    ./ordena binaria $n entrada.txt >> resultado.txt
    ./ordena selecao $n entrada.txt >> resultado.txt
    ./ordena shell $n entrada.txt >> resultado.txt
    ./ordena heap $n entrada.txt >> resultado.txt
    ./ordena quicksortini $n entrada.txt >> resultado.txt
    ./ordena quicksortcentro $n entrada.txt >> resultado.txt
    ./ordena quicksortmediana $n entrada.txt >> resultado.txt
    ./ordena merge $n entrada.txt >> resultado.txt
    ./ordena radix $n entrada.txt >> resultado.txt
    ./ordena bucket $n entrada.txt >> resultado.txt
    n=$((n*10))
done

echo "Enter to exit"
read ENTER
