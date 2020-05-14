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
	int listenfd = 0, connfd = 0;
	struct sockaddr_in serv_addr;
	char sendBuff[32];
	listenfd = socket(AF_INET, SOCK_STREAM, 0);

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons (7777);

	bind(listenfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr));
	listen(listenfd, 10);

	while (1)
	{
        connfd = accept(listenfd, (struct sockaddr*) NULL, NULL);
        strcpy(sendBuff, "You has been connected to server\n");
        write(connfd, sendBuff, strlen(sendBuff));
        close(connfd);
        sleep(10);
	}


	return 0;
}
