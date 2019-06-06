#include <stdio.h>
#include <stdlib.h>

int* recuperarVetorArquivo(char* nomeArquivo, int n){
    FILE* arquivo = fopen(nomeArquivo,"r");
    if(arquivo != NULL){
        int* vetor = (int*) malloc(n*sizeof(int));
        for(int i = 0; i<n; i++)
            fscanf(arquivo,"%d\n",&vetor[i]);
        fclose(arquivo);
        return vetor;
    }
    printf("Arquivo não encontrado!\n");
    return NULL;
}

void gravarVetor(int* vetor, int n, char* nomeArquivo){
    FILE* arquivo = fopen(nomeArquivo,"w");
    for(int i = 0; i < n; i++)
        fprintf(arquivo,"%d\n",vetor[i]);
    fclose(arquivo);
} 
