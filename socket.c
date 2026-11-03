#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>

#define PORT 8080
#define ADDR "127.0.0.4"
#define BUFFER_SIZE 80

int main(){
	char buf[BUFFER_SIZE];
	socklen_t lenaddr = sizeof(ADDR);
	struct sockaddr_in serv_addr;

	int server_socket = socket(AF_INET, SOCK_STREAM, 0);
  	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	serv_addr.sin_addr.s_addr = inet_addr(ADDR);
	serv_addr.sin_zero[8]='\0';


	if (!server_socket){
		printf("Socket was not opened.\n");
		return 1;
	}

	if(bind(server_socket, (struct sockaddr*)&serv_addr, sizeof(struct sockaddr))<0){
		return 1;
	};

	if(listen(server_socket, 0)<0){
		printf("Listening has failed!\n");
		return 1;
	};

	int client_socket = accept(server_socket, (struct sockaddr *)&serv_addr, &lenaddr);
	if (client_socket < 0) {
		printf("Acceptance has failed! \n");
		return 1;
	}


	recv(client_socket, buf, BUFFER_SIZE,0);


	close(server_socket);
	printf("Buffer: %s\n:", buf);

}
	



