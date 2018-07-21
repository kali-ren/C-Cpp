#include<stdio.h>
#include<stdlib.h>
//lista circular

typedef struct no{
	int id;
	struct no *seg;
}no;

void show(no *lst){
	no *p;
	for(p=lst->seg; p != lst; p=p->seg)
		printf("%d\n",p->id);

}

void insert(int item,no *lst){
	no *p,*new;
	p=lst;
	new=malloc(sizeof(no));
	new->id=item;
	if(p->seg==NULL){
		printf("sister\n");
		p->seg=new;
		new->seg=lst;
	}
	else{
		printf("morphine\n");
		while(p->seg != lst){
			p=p->seg;
		}
		p->seg=new;
		new->seg=lst;
	}

}
/*void delete(){

}
*/
main(){
	no *lista;
	lista=malloc(sizeof(no));
	lista->seg=NULL;
	insert(1,lista);
	insert(11,lista);
	insert(111,lista);				
	show(lista);
}
