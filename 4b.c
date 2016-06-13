#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define vezes 25
#define max 500000

//vetor dinamico
void alocation(int tam){
	int i;
	int *v = (int *)malloc(tam * sizeof(int));
	for(i=0;i<tam;i++){
		v[i] = 5;
	}
	free(v);
}	

main(){
	int tam=1000,i,j;
	double media;
        clock_t tempoInicio, tempoFinal;
	FILE *fp;
	fp = fopen("dinamico.txt","w");
	if(fp == NULL){
		printf("deu ruim\n");
	}		
	while(tam <= max){
		media=0;
		tempoInicio = clock();
		for(j = 0; j < vezes ; j++)
			alocation(tam);
		tempoFinal=clock();
		double tempoGasto = (double)(tempoFinal-tempoInicio)/(CLOCKS_PER_SEC/1000);
		media += tempoGasto;
		media /= vezes;
		printf("%d %f\n",tam,media);
		fprintf(fp,"%d %f\n",tam,media);
		tam += 1000;
   	}
	fclose(fp);

}
