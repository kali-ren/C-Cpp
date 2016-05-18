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
int busca(int i,vetor *prox){//optimizar !
	int r;	
	r = i%7;
	no *aux;
	aux=prox[r].noo;
	if(aux==NULL){
		printf("valor nao existe\n");
		return 0;
	}
	else{
		while(aux != NULL && aux->id != i){
			if(aux->id == i){
				printf("valor existe !\n");
				return 1;
			}
			else{
				aux=aux->prox;
			}
		}
		printf("valor nao existe\n");
		return 0;
	}
}
void remocao(int i, vetor *prox){
	int r;
	no *ant,*p;
	r = i%7;
	ant = prox[r].noo;
	p = ant->prox;
	if(ant->id == i && p != NULL){
		ant->id=p->id;
		ant->prox = p->prox;
		free(p);
	}
	else if(ant->id == i && p == NULL){
		prox[r].noo=NULL;		
		
	}
	else{
		while(p != NULL && p->id !=i ){
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
	int i, v[9]={0,1,85,6,36,46,89,112,44},a;
	for(i=0;i<9;i++)
		insercaomod(v[i],proxeneta);
	
	whenitjustgoestoshow(proxeneta);
//	remocao(36,proxeneta);
//	remocao(85,proxeneta);
//	remocao(1,proxeneta);
	printf("////////////////////////\n");
	whenitjustgoestoshow(proxeneta);
	a=busca(10,proxeneta);
	printf(" %d\n",a);


}
