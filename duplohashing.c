#include<stdio.h>
#include<stdlib.h>
//doublhash
#define size 7

typedef struct vetor{
	int va,flag;
}vetor;

vetor proxeneta[size];

void insert(int i, vetor *pv){
	int r;
	r = i % size;
	if(pv[r].flag == 1){
		newf(i,vetor*pv);
	}
	else{
		pv[r].va = i;
		pv[r].flag = 1;
	}

}

void whenitjustgoestoshow(vetor *p){
}
int newf(int i,vetor *pv){
	int 
}

main(){
	int i, v[5]={89,18,49,60,69};
	for(i=0;i<5;i++)
		insert(i,proxeneta);
