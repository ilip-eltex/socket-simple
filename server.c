// Server
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main ()
{
	printf ("%d\n", sizeof(char));
	int listenfd = 0, connfd = 0;
	struct sockaddr_in serv_addr, client_addr;
	char sendBuff[1024], recvBuff[5];
	memset(sendBuff, '\0', sizeof(sendBuff));
	listenfd = socket(AF_INET, SOCK_STREAM, 0);

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("192.168.0.5");
	serv_addr.sin_port = htons (7777);
    printf("Wait for connection...\n");
	bind(listenfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr));
	listen(listenfd, 10);
	connfd = accept(listenfd, (struct sockaddr*) NULL, NULL);
    printf("Accept connection\n");
    	while (1)
	{
		
		recv (connfd, (void*) recvBuff, 5, 0);
		printf ("%s", recvBuff);
		memset (sendBuff, '\0', sizeof(sendBuff));

	}
        close(listenfd);
	printf("a?\n");


	return 0;
}
