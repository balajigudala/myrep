#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>

void main()
{
	
	int sockfd,ret;
	struct sockaddr_in serv;
	char buf[256]="hi";
	sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	printf("%d\n",sockfd);
	bzero(&serv,sizeof(serv));
	serv.sin_addr.s_addr=inet_addr("127.0.0.1");
	serv.sin_port=htons(5000);
	serv.sin_family=AF_INET;

	connect(sockfd,(struct sockaddr*)&serv,sizeof(serv));
	ret=send(sockfd,"lord",strlen("lord"),0);
	ret=recv(sockfd,buf,256,0);
	printf("%d\n",ret);
	write(1,buf,ret);

}


