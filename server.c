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
	char sendBuff[1024];
	memset(sendBuff, '0', sizeof(sendBuff));
	listenfd = socket(AF_INET, SOCK_STREAM, 0);

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_addr.sin_port = htons (7777);
    printf("Wait for connection...\n");
	bind(listenfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr));
	listen(listenfd, 10);
	connfd = accept(listenfd, (struct sockaddr*) NULL, NULL);
    printf("Accept connection\n");
    strcpy(sendBuff, "Hello!\n");
    printf ("sending: %s", sendBuff);
        send(listenfd, (void*)sendBuff, sizeof("Hello!\n"), 0);
        close(listenfd);



	return 0;
}
