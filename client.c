#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd = 0, n = 0;
    char recvBuff[1024];
    struct sockaddr_in serv_addr;

    memset(recvBuff, '\0',sizeof(recvBuff));
    printf ("%d\n", sizeof(char));
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Error : Could not create socket \n");
        return 1;
    }

    

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(7777);
    serv_addr.sin_addr.s_addr = inet_addr("192.168.0.5");


    if( connect(sockfd, (struct sockaddr_in *)&serv_addr, sizeof(serv_addr)) < 0)
    {
       printf("\n Error : Connect Failed \n");
       return 1;
    }



      	
	char sendBuff[5];
	memset (sendBuff, '\0', sizeof(sendBuff));
	
	while ( strcmp (sendBuff, "exit") )
	{
		fgets (sendBuff, 4, stdin);
		sendBuff[4] = '\n';
		send (sockfd, (void*) sendBuff, sizeof(sendBuff), 0);
		memset (sendBuff, '\0', sizeof(sendBuff));
	}
        
	close(sockfd);

    return 0;
}
