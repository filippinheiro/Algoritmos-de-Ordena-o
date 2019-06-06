#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ordenacao.h"
#include "arquivo.h"


int main(int argc, char** argv){

    char* algoritimo = argv[1];
    int n = atoi(argv[2]);
    char* arquivo = argv[3];
    int* vet = recuperarVetorArquivo(arquivo,n);



    if(vet != NULL){
        double tempo = 0;
		int comp = 0;
		int troca = 0;
		char metodo[20] = "";

		clock_t tempo_ini, tempo_fim;

        if(!strcmp("bolha",algoritimo)){
			tempo_ini = clock();
			bolha(vet,n,&comp,&troca);
			tempo_fim = clock();
            strcpy(metodo, "Bolha");
        }
        else if(!strcmp("insercaoDireta",algoritimo)){
            tempo_ini = clock();
			insercaoDireta(vet,n,&comp,&troca);
			tempo_fim = clock();
            strcpy(metodo, "insercaoDireta");
        }
        else if(!strcmp("binaria",algoritimo)){
            tempo_ini = clock();
			binaria(vet,n,&comp,&troca);
			tempo_fim = clock();
            strcpy(metodo, "binaria");
        }
        else if(!strcmp("selecao",algoritimo)){
            tempo_ini = clock();
			selecao(vet,n,&comp,&troca);
			tempo_fim = clock();
            strcpy(metodo, "selecao");
        }
        else if(!strcmp("shell",algoritimo)){
            tempo_ini = clock();
			shell(vet,n,&comp,&troca);
			tempo_fim = clock();
            strcpy(metodo, "shell");
        }
        else if(!strcmp("heap",algoritimo)){
            tempo_ini = clock();
			heap(vet,n,&comp,&troca);
			tempo_fim = clock();
            strcpy(metodo, "heap");
        }
        else if(!strcmp("quicksortini",algoritimo)){
            tempo_ini = clock();
			quick(vet,0,n,&comp,&troca,1);
			tempo_fim = clock();
            strcpy(metodo, "quicksortini");
        }
        else if(!strcmp("quicksortcentro",algoritimo)){
            tempo_ini = clock();
			quick(vet,0,n,&comp,&troca,2);
			tempo_fim = clock();
            strcpy(metodo, "quicksortcentro");
        }
        else if(!strcmp("quicksortmediana",algoritimo)){
            tempo_ini = clock();
			quick(vet,0,n,&comp,&troca,3);
			tempo_fim = clock();
            strcpy(metodo, "quicksortmediana");
        }
        else if(!strcmp("merge",algoritimo)){
            tempo_ini = clock();
			merge(vet,0,n-1,&comp,&troca);
			tempo_fim = clock();
            strcpy(metodo, "merge");
        }
        else if(!strcmp("radix",algoritimo)){
            tempo_ini = clock();
			radix(vet,n,&comp,&troca);
			tempo_fim = clock();
            strcpy(metodo, "radix");
        }
        else if(!strcmp("bucket",algoritimo)){
            tempo_ini = clock();
			bucket(vet,n,&comp,&troca);
			tempo_fim = clock();
            strcpy(metodo, "bucket");
        }
        else{
            printf("algoritimo inválido!\n");
            return 0;
        }
        tempo = (tempo_fim - tempo_ini) / (double) CLOCKS_PER_SEC;

        printf("%f\t",tempo);
        printf("%d\t",comp);
        printf("%d\t\n",troca);
        //printf("%s\t\n",metodo);

        gravarVetor(vet,n,"saida.txt");
    }
    free(vet);

    return 0;
}
