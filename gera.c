#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "arquivo.h"

int* gerarCrecente(int);

int* gerarDecrecente(int);

int* gerarAleatorio(int);

int main(int argc, char** argv){
    int tamanho = (int) atoi(argv[2]);
    char* argumento = argv[1];
    int* vetor = NULL;
    
    if(!strcmp("-c",argumento))
        vetor = gerarCrecente(tamanho);
    else if(!strcmp("-d",argumento))
        vetor = gerarDecrecente(tamanho);
    else if(!strcmp("-a",argumento))
        vetor = gerarAleatorio(tamanho);
    else
        printf("Argumento inválido!\n");

    
    if(vetor != NULL)
        gravarVetor(vetor, tamanho,"entrada.txt");
    
    free(vetor);
    
    return 0;
}


int* gerarCrecente(int n){
    int* vetor = (int*) malloc(n*sizeof(int));
    if(vetor != NULL)
        for(int i = 0; i<n; i++)
            vetor[i] = i+1;
    
    return vetor;
}

int* gerarDecrecente(int n){
    int* vetor = (int*) malloc(n*sizeof(int));
    if(vetor != NULL)
        for(int i = 0; i<n; i++)
            vetor[i] = n-i;

    return vetor;
}

int* gerarAleatorio(int n){
    srand(time(NULL));
    int aux;
    int* vetor = gerarCrecente(n);
    for(int i = 0; i<n; i++){
        int r = rand() % n;
        aux = vetor[i];
        vetor[i] = vetor[r];
        vetor[r] =aux;
    }
    return vetor;
}