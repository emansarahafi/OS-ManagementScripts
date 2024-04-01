//Task 3 - Script B by Eman Sarah Afi (A00051) & Yousef Elsonbaty (A00138)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void error(const char *msg)
{
	perror(msg);
	exit(0);
}

//Main function
int main(int argc, char *argv[])
{
	int sockfd, portno = 9999;
	struct sockaddr_in serv_addr;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		error("ERROR opening socket");
	bzero(&serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_addr.sin_port = htons(portno);

	if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == 0)
	{
		printf("This is Client B\n");
		char buf[1024];
		strncpy(buf, "Hello server! This is Client B.", 32);
		write(sockfd, buf, strlen(buf));
		int count = read(sockfd, buf, 1024);
		printf("Got echo of \"%s\" from server\n", buf);
		shutdown(sockfd, SHUT_RDWR);
	}
	else
		error("ERROR connecting");
}
