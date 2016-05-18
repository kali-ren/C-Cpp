#include<stdio.h>
#include<stdlib.h>

typedef struct no{
	int id,flag;
	struct no *prox;
}no;

typedef struct vetor{
	int flag;
	struct no *noo;
	
}vetor;

vetor proxeneta[7];


void insercaomod(int i, vetor *prox){
	int r;
	r = i%7;
	printf("%dmod%d=%d\n",i,7,r);
	no *new;
	new=malloc(sizeof(no));
	new->id=i;
	if(prox[r].flag == 1 ){
			new->prox = prox[r].noo;
			prox[r].noo = new;
	}	

	else{
		prox[r].noo = new;
		prox[r].flag = 1;
	}
}
void remocao(int i, vetor *prox){
	int r;
	no *ant,*p;
	r = i%7;
	ant = prox[r].noo;
	p = ant->prox;
	if(ant->id==i){
		printf("toca no calleri q eh gool\n");
		ant->id=p->id;
		printf("%d\n",p->id);
		ant=p;
		p=p->prox;
		ant->prox=p->prox;
		free(p);
	}
	else{
		while(p != NULL && p->id !=i){
			ant=p;
			p=p->prox;
		}
		ant->prox=p->prox;
		free(p);
	}		
}
void whenitjustgoestoshow(vetor *prox){
	int i;
	no *aux;
	for(i=0;i<7;i++){
		printf("proxeneta[%d]",i);
		aux = prox[i].noo;
		while(aux != NULL){
			printf(" -> %d ",aux->id);
			aux = aux->prox;
		}
		printf("\n");
	}


}		
main(){
	int i, v[9]={0,1,85,6,36,46,89,112,44};
	for(i=0;i<9;i++)
		insercaomod(v[i],proxeneta);
	
	whenitjustgoestoshow(proxeneta);
	remocao(112,proxeneta);
	printf("////////////////////////\n");
	whenitjustgoestoshow(proxeneta);


}











