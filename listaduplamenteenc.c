#include<stdio.h>
#include<stdlib.h>


typedef struct no{
	int id;
	struct no *pr, *an; 
}no;
void show(no *lst){
	no *p;
	p=lst;
	for(p=p->pr; p!=NULL; p=p->pr){
//		printf("%d\n",p->an->id);
		printf("%d\n",p->id);

	}
	
}
void showadd(no *lst){
	no *p;
	p=lst;
	for(p=p->pr;p!=NULL;p=p->pr){
		printf("%p\n",p);
		printf("%p\n",p->an);
	}
}
void delete(int i, no *lst){
	no *p,*a;
	p=lst->pr;
	a=lst;
	while(p->id != i && p->pr != NULL){
		p=p->pr;
		a=a->pr;		
	}
	if(p->pr==NULL){
		a->pr=p->pr;	
		free(p);
	}
	else{
		a->pr=p->pr;
		p->pr->an = a;
		free(p);
	}
}
void insert(int item, no *lst){
	no *new,*p;
	new=malloc(sizeof(no));
	new->id=item;	
	if(lst->pr==NULL){
		lst->pr=new;
		new->an=lst;
	}
	else{
		p=lst->pr;
		while(p->pr != NULL)
			p=p->pr;
		p->pr=new;
		new->an=p;
	}
}

main(){
	no *l;
	l=malloc(sizeof(no));
	l->pr=NULL;
	insert(1,l);
	insert(21,l);
	insert(17,l);
	insert(44,l);
	insert(34,l);
//	show(l);
	delete(34,l);
	showadd(l);
}







