#include<stdio.h>
#include<stdlib.h>
//doublhash
#define size 7

typedef struct vetor{
	int va,flag;
}vetor;

vetor proxeneta[size];

int primo(int i){
	int j,count=0;
	for(j=1;j<=i;j++){
		if(i%j==0)
			count++;		
	}
	if(count==2){
		return 1;
	}
	else{
		return 0;
	}
}

int newp(int primold){
	int np,i,a=0;
	i = primold-1;
	if(i>1){
		while(i>1 && a==0){
			if(primo(i)==1){
				a=1;
			}
			else{
				i--;
			}
		}
		if(a==1){
			return i;
		}
	}
	else{
		printf("deu ruim\n");
		return 0;
	}
}

void insert(int s, int i, vetor *pv){
	int r,np;
	r = i % s;
	printf("%dmod%d=%d\n",i,s,r);
	if(pv[r].flag == 1){
		np = newp(s);
		if(np==1 || np==0){//gato da porra !
			printf("data perdido !\n");
		}
		else{
			printf("novo primo %d\n",np);
			insert(newp(s),i,pv);
		}
	}
	else{
		pv[r].va = i;
		pv[r].flag = 1;
	}

}

void whenitjustgoestoshow(vetor *p){
	int i;
 	for(i=0;i<size;i++){
		printf("v[%d] = %d\n",i,p[i].va);		
	}
}

main(){
	int i, v[5]={89,18,49,60,69};
	for(i=0;i<5;i++)
		insert(size,v[i],proxeneta);
	whenitjustgoestoshow(proxeneta);
}







