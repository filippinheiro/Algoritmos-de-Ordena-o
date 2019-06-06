#include <stdio.h>
#include <time.h>

int main()
{
    clock_t tempo_ini, tempo_fim;
    tempo_ini = clock(); //armazena tempo de início

    getchar();
    //algoritmo a ser computado o tempo.


    tempo_fim = clock(); //armazena tempo que finalizou

    printf("Tempo:%f segundos",(tempo_fim - tempo_ini) / (double)CLOCKS_PER_SEC);
    //double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //printf("Tempo gasto: %g ms.", Tempo);
    getchar();

    return 0;
}
