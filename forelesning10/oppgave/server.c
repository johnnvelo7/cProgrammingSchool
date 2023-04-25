#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <time.h>

int main (int iArgC, char *apszArgV[]){

	//LISTEN
	int sockFd = 0, connectFd = 0;
	struct sockaddr_in serv_addr;
	
	char sendBuff[1025]; // MAKS SIZE, but can use 256
	time_t ticks;
	
	//SETTING SIZES 
	sockFd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockFd < 0)
		printf("ERROR opening socket");
	
	memset(&serv_addr, '0', sizeof(serv_addr));
	memset(sendBuff, '0', sizeof(sendBuff));
	
	int iPort = atoi("4444");
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(iPort);
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sockFd, (struct sockaddr *) &serv_addr, sizeof(serv_addr))<0)
		printf("ERROR on binding");
	
	//LISTEN 
	listen(sockFd, 5);
	 
	//WHILE FALSE
	while(1){
		connectFd = accept(sockFd, (struct sockaddr*)NULL, NULL);
		ticks = time(NULL);
		snprintf(sendBuff,sizeof(sendBuff),"%.24s\r\n", ctime(&ticks));
		write(connectFd,sendBuff,strlen(sendBuff));
		close(connectFd);
		sleep(1);
	}
	return 0;
}

