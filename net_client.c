#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main(int argc,char **argv)
{
	int recv_fd;
	int res;
	struct sockaddr_in myaddr;
	myaddr.sin_family=AF_INET;
	myaddr.sin_addr.s_addr=inet_addr("115.28.26.84");

	myaddr.sin_port = htons(4603);
	char recv_buf[100];
	char send_buf[100];

	//1,socket
	recv_fd=socket(AF_INET,SOCK_STREAM,0);
	if(recv_fd == -1)
	{
		perror("socket error");
		exit(1);
	} 
	//2,bind
	if(connect(recv_fd,(struct sockaddr *)&myaddr,sizeof(myaddr))==-1)
	{
		perror("connect error ");
		exit(1);
	}
	
	if(strlen(argv[1])>0)
	{
		res=send(recv_fd,argv[1],6,0);
		printf("发送: %s\n",send_buf);
	}
	else
	{
		perror("输入为空,请重新输入...\n");
	}
	
	close(recv_fd);
}
