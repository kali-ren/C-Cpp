#include<stdio.h>
#include<stdlib.h>

#define size 5
typedef struct no{
	int id,flag;
	struct no *prox;
}no;

typedef struct vetor{
	int flag;
	struct no *noo;
	
}vetor;

vetor proxeneta[size];


void insercaomod(int i, vetor *prox){
	int r;
	r = i%size;
	printf("%dmod%d=%d\n",i,size,r);
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
	r = i%size;
	no *aux;
	aux=prox[r].noo;
	if(aux==NULL){
		printf("valor nao existe\n");
		return 0;
	}
	else{
		while(aux != NULL && aux->id != i)
				aux=aux->prox;
		if(aux == NULL){
			printf("valor nao existe");
			return 0;
		}
		else if(aux->id == i){
			printf("valor existe");
			return 1;
		}
		else{
			printf("valor nao existe\n");
			return 0;
		}	
	}
}
void remocao(int i, vetor *prox){
	int r;
	no *ant,*p;
	r = i%size;
	ant = prox[r].noo;
	p = ant->prox;
	if(busca(i,prox)==0){
		printf("%d nao existe na estrutura !!\n",i);
	}
	else{
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
}
void whenitjustgoestoshow(vetor *prox){
	int i;
	no *aux;
	for(i=0;i<size;i++){
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
	int i, v[20]={16,18,22,29,27,2,18,13,12,28,31,81,1,19,8,14,91,32,1,31},a;
	for(i=0;i<20;i++)
		insercaomod(v[i],proxeneta);
	
	whenitjustgoestoshow(proxeneta);
	remocao(81,proxeneta);
	remocao(71,proxeneta);
	remocao(14,proxeneta);
	remocao(22,proxeneta);
	remocao(1,proxeneta);
	printf("////////////////////////\n");
	whenitjustgoestoshow(proxeneta);
//	a=busca(71,proxeneta);
//	printf(" %d\n",a);


}

