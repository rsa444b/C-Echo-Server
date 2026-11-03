#include <stdio.h>
#include <sys/socket.h>

#define ADDR "127.0.0.1"

int main(){

	socklen_t lenaddr = sizeof(ADDR);
	struct sockaddr_in address = ADDR;

	int server_socket = socket(AF_INET, SOCK_STREAM, 0);

	if (!server_socket){
		printf("Socket was not opened.\n");
		return 1;
	}

	if(!bind(server_socket, ADDR, sizeof(ADDR))){
		printf("Bind has failed!\n");
		return 1;
	}

	if(!listen(server_socket, 0)){
		printf("Listening has failed!\n");
		return 1;
	}

	//accept(server_socket, &ADDR, &lenaddr);


}
	


}
