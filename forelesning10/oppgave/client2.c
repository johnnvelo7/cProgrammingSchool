#include <arpa/inet.h> // for inet_addr()
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h> // bzero()
#include <sys/socket.h>
#include <unistd.h> // read(), write(), close()

#define MAX 256
#define SA struct sockaddr

void chatFunc(int socketFd);

int main(int iArgC, char *apszArgV[]){

	int socketFd, connectFd;
	struct sockaddr_in serv_addr, client;
	
	//socket creation
	socketFd = socket(AF_INET, SOCK_STREAM, 0);
	if (socketFd < 0){
		printf("Socket creation failed...\n");
		return 1;
	}
	else{
		printf("Socket successfully created...\n");
	}
	
	bzero(&serv_addr, sizeof(serv_addr));
	
	//Assign IP and PORT
	int iPort = atoi("4444");
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_addr.sin_port = htons(iPort);
	
	//connect to the client
	if (connect(socketFd, (SA*)&serv_addr, sizeof(serv_addr)) != 0){
		printf("Connection with the server failed...\n");
		return 1;
	}
	else{
		printf("Connected to the server...\n");
	}
	
	chatFunc(socketFd);
	close(socketFd);

	return 0;
}

void chatFunc(int socketFd){
	char buff[MAX];
	int n;
	
	//loop
	for (;;){
		bzero(buff, sizeof(buff));
		printf("Enter the string : ");
		n = 0;
		while ((buff[n++] = getchar()) != '\n');
		write(socketFd, buff, sizeof(buff));
		bzero(buff, sizeof(buff));
		read(socketFd, buff, sizeof(buff));
		printf("From Server : %s", buff);
		if ((strncmp(buff, "exit", 4)) == 0){
			printf("Client exits... bye!\n");
			break;
		}
	}
}
