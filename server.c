#include<stdlib.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
main()
{
  char buffer[256];
  int c,port,clientsocketid,socketid;
  struct sockaddr_in server;
  int s=sizeof(server);

  //creating a socket 
  socketid=socket(AF_INET,SOCK_STREAM,0);

  //binding socket to a port
  printf("\n Enter port no:");
  scanf("%d",&port);
  server.sin_family=AF_INET;
  server.sin_port=htons(port);
  server.sin_addr.s_addr=INADDR_ANY;
  bind(socketid,(struct sockaddr*)&server,sizeof(server));

  do
  {

    //listen to connection request
    listen(socketid,1);

    //accept connection request
    clientsocketid=accept(socketid,(struct sockaddr*)&server,&s);
    printf("\n Connection established...");

    //receive and print the data
    recv(clientsocketid,buffer,sizeof(buffer),0);
    printf("\n%s\n",buffer);

    //closing the socket
    close(clientsocketid);
  
    printf("\n Enter 1 to continue:");
    scanf("%d",&c);
  }while(c==1);
  close(socketid);
}
