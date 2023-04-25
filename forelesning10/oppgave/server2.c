#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h> // READ() WRITE() CLOSE()

#define MAX 256

#define SA struct sockaddr

//chat function
void chatFunc (int connectFd);

int main (int iArgC, char *apszArgV[]){
	int socketFd, connectFd, len;
	struct sockaddr_in serv_addr, client;
	
	//socket create and verification
	socketFd = socket(AF_INET, SOCK_STREAM, 0);
	if (socketFd < 0){
		printf("Socket creation failed..\n");
		return 1;
	}
	else
		printf("Socket successfully created...\n");
	bzero(&serv_addr, sizeof(serv_addr));
	
	//assigning IP, PORT
	int iPort = atoi("4444");
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(iPort);
	
	//binding newly created socket to given IP
	if((bind(socketFd, (SA*)&serv_addr, sizeof(serv_addr))) != 0){
		printf("Socket binded failed...\n");
		return 1;
	}
	else{
		printf("Socket successfully binded...\n");
	}
		
	//Listen to client
	if((listen(socketFd, 5)) != 0){
		printf("Listen failed...\n");
		return 1;
	}
	else{
		printf("Server is listening...\n");
	}
		
	
	len = sizeof(client);
	
	//accept the data packet from client
	connectFd = accept(socketFd, (SA*)&client, &len);
	if(connectFd < 0){
		printf("Server accept failed...\n");
		return 1;
	}
	else{
		printf("Server accepted the client...\n");
	}
	chatFunc(connectFd);
	close(socketFd);
	return 0;
}

void chatFunc (int connectFd){
	char buff[MAX];
	int n;
	
	//loop for chatFunc
	for(;;){
		bzero(buff, MAX);
		//read the message from the client and copy it to the buffer
		read(connectFd, buff, sizeof(buff));
		//print the buffer which contains the client contents
		printf("From client: %s\t To client : ", buff);
		bzero(buff, MAX);
		n = 0;
		//copy server message in the buffer 
		while ((buff[n++] = getchar()) != '\n');
		//send the buffer to client
		write(connectFd, buff, sizeof(buff));
		//if message contains: Exit, chat ends)
		if(strncmp("exit", buff, 4) == 0) {
			printf("Server exits..... bye! \n");
			break; //break out of the loop
		}
	}
}
