#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>

#define ADDR "127.0.0.4"
#define PORT 8080

int main(){
	socklen_t lenaddr = sizeof(ADDR);
	struct sockaddr_in client_addr;

	int client_socket = socket(AF_INET, SOCK_STREAM, 0);
//TODO: 	check if socket is created
	client_addr.sin_family = AF_INET;
	client_addr.sin_port = htons(PORT);
	
	if (inet_pton(AF_INET, ADDR, &client_addr.sin_addr) <= 0) {
        	return 1;
    }
	if (connect(client_socket, (struct sockaddr *)&client_addr, sizeof(client_addr))){
		printf("Connection went wrong!\n");
		return 1;
	}

	write(client_socket, "123", 4);


	close(client_socket);

	return 0;
}
