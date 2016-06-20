#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define max 100000


typedef struct no{
	int id;
	struct no *prox;
}no;

void show(no *l){
	no *p;
	for(p = l->prox; p != NULL; p = p->prox)
		printf("%d\n",p->id);
}
void insert(no *pc){
	no *p,*new,*end;
	p=pc;
	new=malloc(sizeof(no));
	new->id=5;
	if(p->prox==NULL){
		p->prox=new;
		end=new;
	}
	else{
		end->prox=new;
		end=new;
	}
}

void ba(int min, int intervalo, no *pc){
	int i,x;
	double media=0;
	double tempoGasto;
	clock_t tempoInicio, tempoFinal;
	no *aux;
	aux=pc;
	printf("intervalo %d\n",intervalo);
	x = min + rand() % intervalo;
	printf("numero gerado %d\n",x);
	tempoInicio = clock();
	for(i=0; i<x; i++)
		aux = aux->prox;
	tempoFinal = clock();
	tempoGasto = (double)(tempoFinal-tempoInicio)/(CLOCKS_PER_SEC/1000);
	printf("%f tempo medio\n",tempoGasto);
}	

main(){
/*	FILE *fp;
	fp = fopen("saida.txt","w");
	if(fp==NULL){
		printf("falha\n");
	}*/
	int i,tam=1000,min=1;
	no head,*c;
	head.prox = NULL;
	c = &head;
	srand((unsigned)time(NULL));
	for(i=1;i<=max;i++){
		insert(c);
	}
	while(tam <= max){
		ba(min,tam,c);
		tam += 1000;
		min += 1000;
		printf("minimum %d\n",min);
	}
}

