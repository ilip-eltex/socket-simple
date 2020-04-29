#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
int main ()
{
	int toServer = socket(AF_INET, SOCK_STREAM, 0);
	if (toServer == -1) 
	{
		write(stderr, "Cann't get socket descr. App halted\n");
		return 1;
	}	
	return 0;
}
