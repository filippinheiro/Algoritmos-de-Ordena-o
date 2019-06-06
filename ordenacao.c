#include <stdio.h>
#include <stdlib.h>
#define TAM 5

//Estrutura apenas para o bucketSort
typedef struct balde{
	int qtd;
	int valores[TAM];
}Balde;


void bolha(int *vetor, int n, int* comp, int* troca){
   	int temp;
	for (int i = 1; i < n; i++)
		for(int j = 0; j < (n-i) ; j++){
			*comp += 1;
            if (vetor[j] > vetor[j + 1]){
                *troca += 1;
				temp = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = temp;
			}
        }
}

void insercaoDireta(int *vetor, int n, int* comp, int* troca ){
	int aux,j;
	for(int i = 1; i < n; i++){
		aux = vetor[i];
		j = i-1;
		*comp += 1;
		while(j >= 0 && aux < vetor[j]){
			*comp += 1;
			*troca += 1;
			vetor[j+1] = vetor[j];
			j--;
		}
		
		if( j != i-1)
			vetor[j+1] = aux;
		
	}

}

void binaria(int* vetor, int n, int* comp, int* troca){
	int aux,esq,dir,meio;
		
	for(int i = 1; i<n; i++){
		aux = vetor[i];
		esq = 0;
		dir = i;
		while(esq<dir){
			meio = (esq+dir)/2;
			*comp += 1;
			if(vetor[meio] <= aux)
				esq = meio + 1;
			else
				dir = meio;
		}

		for(int j = i; j>esq; j--){
			*comp += 1;
			*troca += 1;
			vetor[j] = vetor[j-1];
		}

		vetor[dir] = aux;
	}
}

void selecao(int* vetor, int n, int* comp, int* troca){
  	int menor,aux;
	for(int i = 0; i<n; i++){
		menor = i;
		for( int j = i+1; j < n; j++){
			*comp += 1;
			if(vetor[j] < vetor[menor])
				menor = j;
		}
		if(i!= menor){
			*troca += 1;
			aux = vetor[i];
			vetor[i] = vetor[menor];
			vetor[menor] = aux;
		}
	}
}

void shell(int* vetor, int n, int* comp, int* troca){
   	int aux,i,j;
	int h = 1;

	while(h<n)
		h = 3*h+1;
	
	while(h>1){
		h = h/3;
		for(i = h; i < n; i++){
			aux = vetor[i];
			j = i-h;
			*comp += 1;
			while(j>=0 && aux < vetor[j]){
				*troca += 1;
				vetor[j+h] = vetor[j];
				j = j-h;
			}
			vetor[j+h] = aux;
		}
	}

}

void criaHeap(int* vetor, int ini, int fim, int* comp, int* troca){
	int aux = vetor[ini];
	int j = ini*2+1;

	while(j <= fim){
		if(j<fim){
			*comp += 1;
			if(vetor[j]<vetor[j+1])
				j++;
		}
		*comp += 1;
		if(aux < vetor[j]){
			*troca += 1;
			vetor[ini] = vetor[j];
			ini = j;
			j = 2*ini+1;
		}else{
			j = fim + 1;
		}
	}
	vetor[ini] = aux;
}

void heap(int* vetor, int n, int* comp, int* troca){

	int aux, i;
	for(i = (n-1)/2; i >= 0; i--){
		criaHeap(vetor,i,n-1,comp,troca);
	}
	for(i = n-1; i>=1; i--){
		*troca += 1;
		aux = vetor[0];
		vetor[0] = vetor[i];
		vetor[i] = aux;
		criaHeap(vetor,0,i-1,comp,troca);
	}
}

//https://pt.wikipedia.org/wiki/Quicksort
/**
*	tipo:
*	1 - quicksortini
*	2 - quicksortcentro
* 3 - quicksortmediana
*/
void quick(int* vetor, int ini, int fim, int* comp, int* troca, int tipo){
	int i, j, pivo, aux;
	i = ini;
	j = fim-1;

	//escolha do pivo
	if(tipo == 1)
		pivo = vetor[ini]; // primeiro
	else if(tipo == 2)
		pivo = vetor[(ini + fim) / 2]; //central
	else if(tipo == 3){
		int aux[] = {vetor[ini],vetor[(ini+fim)/2],vetor[fim]};
		int a = 0, b = 0; // só para nõa contabilizar a troca e comparações
		selecao(aux,3,&a,&b);
		pivo = aux[1]; //mediana
	}
	
	while(i <= j){
		
    while(vetor[i] < pivo && i < fim){
      *comp += 1;
      i++;
    }
		
    while(vetor[j] > pivo && j > ini){
      *comp += 1;
      j--;
    }
		
		if(i <= j){
      *troca += 1;
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			i++;
			j--;
		}
	}
	if(j > ini)
		quick(vetor, ini, j+1, comp, troca, tipo);
	if(i < fim)
		quick(vetor, i, fim,comp,troca,tipo);
}


void intercalar(int vetor[],int inicio, int fim, int meio, int* comp, int* troca){
	int i = inicio;
	int j = meio + 1;
	int k = 0;
	int nAux = (fim - inicio)+1;
	int* vetAux = (int*) malloc(nAux*sizeof(int));
	
	if(vetAux != NULL){
		while((i <= meio) || (j<= fim)){
			*comp += 1;
			if((i == meio+1) || ((vetor[j] < vetor[i]) && (j!=fim+1))){
				*troca += 1;
				vetAux[k] = vetor[j];
				j++;
				k++;
			}else{
				*troca += 1;
				vetAux[k] = vetor[i];
				i++;
				k++;
			}
		}

		for(i = inicio; i <=fim; i++){
			vetor[i] = vetAux[i-inicio];
		}
	}

	free(vetAux);
}
void merge(int* vetor, int ini, int fim, int* comp, int* troca){
    if(ini<fim){
    	int meio = (ini+fim)/2;
    	merge(vetor,ini,meio,comp,troca);
    	merge(vetor,meio+1,fim,comp,troca);
    	intercalar(vetor, ini,fim,meio,comp,troca);
    }
}

//https://pt.wikipedia.org/wiki/Radix_sort#C%C3%B3digo_em_C
//https://github.com/lettergram/radixSort/blob/master/radix.c
void radix(int* vetor, int n, int* comp, int* troca){
    int i;
    int *aux;
    int maior = vetor[0];
    int exp = 1;

    aux = (int*)calloc(n, sizeof(int));

	// Encontra o maior
    for (i = 0; i < n; i++)
        if (vetor[i] > maior) maior = vetor[i];


    while (maior/exp > 0) {
      int bucket[10] = { 0 };

	  //Conta o número de "chaves" ou dígitos que serão colocados em cada balde
      for (i = 0; i < n; i++)
    	    bucket[(vetor[i] / exp) % 10]++;
    
	  //Adicione a contagem dos intervalos anteriores, Adquire os índices após o final de cada local de intervalo na matriz
      for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	
	  //Use o balde para preencher uma aux
      for (i = n - 1; i >= 0; i--)
    	    aux[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
    	
      for (i = 0; i < n; i++)
    	    vetor[i] = aux[i];
    	exp *= 10;
    }

    free(aux);
}

//https://www.youtube.com/watch?v=4J89y2Pv_qM&t=284s
void bucket(int* vetor, int n, int* comp, int* troca){
	int i, j, maior, menor, qtdBaldes, pos;
	Balde* baldes;
	
	//Achar maior e menor valor
	maior = menor = vetor[0];
	for(i = 1; i<n; i++){
		if(vetor[i]>maior) maior = vetor[i];
		if(vetor[i]<menor) menor = vetor[i];
	}

	//Inicializa baldes
	qtdBaldes = (maior-menor) / TAM +1;
	baldes = (Balde*) malloc(qtdBaldes*sizeof(Balde));
	for(i = 0; i < qtdBaldes; i++)
		baldes[i].qtd = 0;
	
	//Distribui os valores nos baldes
	for(i = 0; i < n; i++){
		pos = (vetor[i] - menor)/TAM;
		baldes[pos].valores[baldes[pos].qtd] = vetor[i];
		baldes[pos].qtd++;
	}

	//Ordena baldes e coloca no array
	pos = 0;
	for(i = 0 ; i < qtdBaldes; i++){
		selecao(baldes[i].valores, baldes[i].qtd,&menor,&maior);
		for(j = 0; j < baldes[i].qtd; j++){
			vetor[pos] = baldes[i].valores[j];
			pos++;
		}
	}
	free(baldes);
}

