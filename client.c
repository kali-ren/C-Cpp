#include <stdio.h>
#include <netdb.h>
#include <strings.h>
#include <time.h>
#include <fcntl.h>

main(){
	int ms;
	int con;
	struct  sockaddr_in alvo;
	fd_set fdset;
	struct timeval tv;
	
	ms = socket(AF_INET,SOCK_STREAM,0);
	fcntl(ms,F_SETFL,O_NONBLOCK);

	alvo.sin_family = AF_INET;
	alvo.sin_port = htons(21);
	alvo.sin_addr.s_addr = inet_addr("192.168.1.1");

	bzero(&(alvo.sin_zero),8);
//	memset(&(alvo.sin_zero),0,sizeof(alvo));
	con = connect(ms, (struct sockaddr *)&alvo,sizeof(alvo)); 
	FD_ZERO(&fdset);
	FD_SET(ms, &fdset);
	tv.tv_sec = 1;
	tv.tv_usec = 0;
/*	if(con == 0){
		printf("porta aberta\n");
		close(ms);
		close(con);
	}
	else{
		printf("porta fechada\n");
	}

}*/
//http://www-usr.inf.ufsm.br/~giovani/sockets/sockets.txt
	if(select(ms+1,NULL,&fdset,NULL,&tv)==1){
		int so_error;
		socklen_t len = sizeof(so_error);
		getsockopt(ms,SOL_SOCKET,SO_ERROR,&so_error,&len);
		if(so_error==0){
			printf("porta aberta\n");
		}
	}
	else{
		printf("porta fechada\n");
	}
	close(ms);
	close(con);
}
//http://stackoverflow.com/questions/2597608/c-socket-connection-timeout
