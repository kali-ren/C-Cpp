#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define maxx 100000

typedef struct no{
	int id,idade,cep,numero;
	char nome[20],complemento[20];
	struct no *prox;
}no;

char alfa[27]={"abcdefghijklmnopqrstuvwxyz"};
int num[10]={0,1,2,3,4,5,6,7,8,9};

void show(no *l){
	no *p;
	for(p = l->prox; p != NULL; p = p->prox)
		printf("%d\n",p->idade);
}
void atribuicao(char letras[27],int num[10],no *cel){//funcao q aleatoriamente atribui valores para os nos
	int nume,cepp,age,i,x,y;
	no *p;
	p=cel;
	char name[20],comp[20];
	age = rand() % 80;
	cepp = rand() % 6;
	nume = rand() % 100;
	for(i=0;i<20;i++){
		x = rand() % 26;
		y = rand() % 26;
		name[i] = letras[x];
		comp[i] = letras[y];
	}

	strcpy(p->nome,name);
	strcpy(p->complemento,comp);
	p->idade = age;
	p->cep = cepp;
	p->numero = nume;
}

void ba(int min, int intervalo, no *pc){//busca aleatoria(ba) do 1o elemento até o xesimo gerado aleatoriamente. ao final tem-se a atribuicao 
	int i,x;
    	no *aux,*aux2;
    	aux=pc->prox;
	printf("intervalo:de %d ate %d\n",min,intervalo);
	x = rand() % (intervalo + 1 - min) + min;
    	printf("numero gerado %d\n",x);
	for(i=0;i<x;i++)
		aux=aux->prox;
	 aux2=aux;//atribuicao de ponteiros de structs.
}
void insert(no *pc){//criar lista
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
	int i,r=1,tam=1000,j,cont=1;
	no head,*c,*aux;
	FILE *fp;
	fp = fopen("3c.txt","w");
	head.prox = NULL;
	c = &head;
	srand((unsigned)time(NULL));
	for(i=1;i<=maxx;i++)
		insert(c);
	for(aux=head.prox; aux == NULL; aux=aux->prox){
		atribuicao(alfa,num,aux);
	}
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
		printf("%d %f\n",cont,media);
		fprintf(fp,"%d %f\n",cont,media);
		r += 1000;
		tam += 1000;
		cont++;

	}
	fclose(fp);
}
