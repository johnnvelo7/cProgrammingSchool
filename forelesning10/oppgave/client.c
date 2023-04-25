#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>

int main (int iArgC, char *apszArgV[]){

	int sockFd = 0, n = 0; 
	char recvBuff[1024];
	struct sockaddr_in serv_addr;
	
	if(iArgC < 2){
		printf("\nUsage: %s <ip of server> \n", apszArgV[0]);
		return 1;
	}

	memset(recvBuff, '0', sizeof(recvBuff));
	if((sockFd = socket(AF_INET, SOCK_STREAM, 0)) <0) {
		printf("ERROR: could not create socket.\n");
		return 1;
	}
	
	memset(&serv_addr, '0', sizeof(serv_addr));
	int iPort = atoi("4444");
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(iPort);
	
	if(inet_pton(AF_INET, apszArgV[1], &serv_addr.sin_addr) < 0){
		printf("INET_PTON ERROR occured.\n");
		return 1;
	}
	
	if (connect(sockFd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))<0){
		printf("Error: connect failed.\n");
		return 1;
	}
	
	while ((n = read(sockFd, recvBuff, sizeof(recvBuff)-1))> 0 ){
		recvBuff[n] = 0;
		if(fputs(recvBuff, stdout) == EOF){
			printf("Error: fputs error.\n");
		}
	}
	
	if (n < 0){
		printf("Read error.\n");
	}
	return 0;
}
