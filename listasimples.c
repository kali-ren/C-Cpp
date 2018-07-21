#include<stdio.h>
#include<stdlib.h>
// lista com head
typedef struct celula {
	int id;
	struct celula *prox;
}celula;
void show(celula *lst){
	celula *p;
	for(p=lst->prox;p!=NULL;p=p->prox){
		printf("%d\n",p->id);
	}
}
void insert(int i,celula *lst){//no final
	celula *p,*new;
	p=lst;
	new=malloc(sizeof(celula));
	new->id=i;
	if(p->prox==NULL){
		p->prox=new;
	}
	else{
		printf("aqui\n");
		while(p->prox != NULL)
			p=p->prox;
		p->prox=new;
	}
}
void delete(int i,celula *lst){
	celula *p,*ant;
	ant=lst;
	p=lst->prox;
	while(p->id != i){
		ant=p;		
		p=p->prox;
	}	
	ant->prox=p->prox;
	free(p);
}
main(){
	celula *lista;
	lista = malloc(sizeof(celula));
	lista->prox=NULL;
	insert(1,lista);
	insert(22,lista);
	insert(21,lista);
	show(lista);
	printf("////////////////////////////////////////////////////////////////////\n");
	delete(21,lista);
	show(lista);
}
