#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 500000
#define vezes 25
//vetor estatico
main()
{
	int tam = 1000,vet[max],i,j;
        clock_t tempoInicio, tempoFinal;	
    	FILE *fp;
	fp = fopen("estatico.txt","w");
	if(fp==NULL){
		printf("faaiou\n");
	}
	while( tam <= max ){
		double media = 0;
		for(i = 0; i < vezes ; i++){
			tempoInicio = clock();
		        for(j = 0; j < tam ; j++)
		            vet[j] = 5;
		        tempoFinal = clock();
		        double tempoGasto = (double)(tempoFinal-tempoInicio)/(CLOCKS_PER_SEC/1000);
		        media += tempoGasto;
		}
		media /= vezes;
		printf("%d %f\n",tam,media);
		fprintf(fp,"%d %f\n",tam,media);
		tam += 1000;
   	 }
	fclose(fp);

}

