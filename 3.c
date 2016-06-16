#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define maxx 100000

typedef struct no{
	int id;
	struct no *prox;
}no;

/*void show(no *l){
	no *p;
	for(p = l->prox; p != NULL; p = p->prox)
		printf("%d\n",p->id);
}*/
void ba(int min, int intervalo, no *pc){
	int i,x;
    	no *aux;
    	aux=pc->prox;
	printf("intervalo:de %d ate %d\n",min,intervalo);
	x = rand() % (intervalo + 1 - min) + min;
    	printf("numero gerado %d\n",x);
	for(i=0;i<x;i++)
		aux=aux->prox;
	//atribuicao
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
main(){
	int i,r=1,tam=1000,j;
	no head,*c;
	FILE *fp;
	fp = fopen("3c.txt","w");
	head.prox = NULL;
	c = &head;
	for(i=1;i<=maxx;i++)
		insert(c);
	while(tam <= maxx){
    		double media=0;
    		double tempogasto;
    		clock_t inicio, final;
		for(j=0;j<100;j++){
			inicio = clock();
			ba(r,tam,c);
			final=clock();
			tempogasto = (double)(final-inicio)/(CLOCKS_PER_SEC/1000);
			media += tempogasto;
		}
		media /= 100;
		printf("%d %f\n",tam,media);
		fprintf(fp,"%d %f\n",tam,media);
		r += 1000;
		tam += 1000;
	}
	fclose(fp);
}

