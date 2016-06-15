#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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
main(){
	int i;
	no head,*c;
	head.prox = NULL;
	c = &head;
	for(i=1;i<=100000;i++){
		insert(c);}
	show(c);

}

