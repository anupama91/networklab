#include<stdlib.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
main()
{
  char buffer[256];
  int c,length,port;
  
  do
  {

    //creating socket
    int socketid=socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in client;
    printf("\nAvailable ports:2343,2344,2345\nWhich port do you want to connect to?");
    scanf("%d",&port);

    //setting port information of socket 
    client.sin_family=AF_INET;
    client.sin_port=htons(port);
    client.sin_addr.s_addr=inet_addr("127.0.0.1");

    //request for connection
    connect(socketid,(struct sockaddr*)&client,sizeof(client));

    //send a message
    printf("\n Enter the data:");
    scanf("%s",buffer);
    send(socketid,buffer,sizeof(buffer),0);
    printf("\n Data transfer successfull!\n");
    close(socketid);
    printf("\nEnter 1 to continue:");
    scanf("%d",&c);
  }while(c==1);
}
