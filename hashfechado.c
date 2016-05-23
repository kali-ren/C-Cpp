#include<stdio.h>
#include<stdlib.h>

#define SIZE 7
//tentativa linear
typedef struct vetor{
	int flag,va;
}vetor;

vetor prox[SIZE];
int vetfull(vetor *v){
	int i,freq=0;
	for(i=0;i<SIZE;i++){
		if (v[i].flag==1)
			freq++;
	}
	if(freq==7)
		return 1;
	else{
		return 0;
	}
}
void insert(int i,vetor *v){
	int j,r;
	r = i % SIZE;
	if(v[r].flag == 1){
		printf("%d colidiu!\n",i);
		if( !vetfull(v) ){//se tem espaço
			j=1;
			while(j < SIZE){
				r=((i+j) % SIZE);
				if (v[r].flag == 0){
					v[r].va = i;
					v[r].flag = 1;
					j=10;
				}
				else{
					j++;
				}
			}
		}
		else{
			printf("sem espaco, dado perdido %d\n",i);
		}
	}

	else{
		v[r].va = i;
		v[r].flag = 1;
	}
}

void whenitjustgoestoshow(vetor *v){
	int i;
 	for(i=0;i<SIZE;i++){
		printf("v[%d] = %d\n",i,v[i].va);		
	}
}
main(){
	int proxeneta[8]={89,18,49,60,69,14,21,28},i;
	for(i=0;i<8;i++){
		insert(proxeneta[i],prox);
	}
	whenitjustgoestoshow(prox);
}







			 
