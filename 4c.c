#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define vezes 25
#define max 500000
//com head

typedef struct celula {
	int id;
	struct celula *prox;
}celula;


void show(celula *l){
	celula *p;
	for(p = l->prox; p != NULL; p = p->prox)
		printf("%d\n",p->id);
}


void insert(int i, celula *lista){
	celula *p,new,*end,*aux;
    	p = lista;
	aux=&new;
	new.id = i;   
	if(p->prox==NULL){   
		p->prox = aux;
		end = p->prox;
	    }
	else{
		end->prox = aux;
		end = end->prox;
	    }
}
void alocation(celula *lista,int tam){
	int i;
	for(i=0;i<tam;i++)
		insert(5,lista);
}	
main(){
	int i,tam=1000;
	FILE *fp;
	fp=fopen("atenexorp.txt","w");
	if(fp==NULL)
		printf("deu ruim\n");
	while (tam <= max){	
		int j;
        	clock_t tempoInicio, tempoFinal;
		double media = 0;
		for(j = 0; j < vezes ; j++){
			tempoInicio = clock();
			celula c,*lista;	
			c.prox = NULL;
			lista = &c;
			alocation(lista,tam);
			tempoFinal = clock();
			double tempoGasto = (double)(tempoFinal-tempoInicio)/(CLOCKS_PER_SEC/1000);
			media += tempoGasto;
		}
        media /= vezes;
	printf("%d  %f\n",tam,media);
	fprintf(fp,"%d %f\n",tam,media);
	tam += 1000;
	}
	fclose(fp);
}

