#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<stdio.h>
void main()
{
	
	
	int sockfd,client_size,ret,newsockfd;
	char buf[500];
	struct sockaddr_in serv,client;
	sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(sockfd<0)
	{
		printf("failed to create socket\n");
		exit(1);
	}
	printf("sockfd:%d\n",sockfd);

	bzero(&serv,sizeof(struct sockaddr_in));

	serv.sin_family=AF_INET;
	serv.sin_port=htons(5000);
	serv.sin_addr.s_addr=INADDR_ANY;

	ret=bind(sockfd,(struct sockaddr*)&serv,sizeof(serv));
	printf("bind:%d\n",ret);

	listen(sockfd,5);

	client_size=sizeof(client);
	newsockfd=accept(sockfd,(struct sockaddr*)&client,&client_size);
	printf("client sockid:%d\n",newsockfd);

	ret=read(newsockfd,buf,256);
	write(1,buf,ret);
	ret=write(newsockfd,"sheshureddy",strlen("sheshureddy"));
	close(newsockfd);
}


