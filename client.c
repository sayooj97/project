#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>

int main(){ 
    char message[50];
    int clientsocket,port;
    struct sockaddr_in serveraddr;
    socklen_t len;
    char rev_msg[50];

    clientsocket = socket(AF_INET,SOCK_STREAM,0);

    bzero((char*)&serveraddr,sizeof(serveraddr));
    len = sizeof(serveraddr);
    serveraddr.sin_family = AF_INET;

    printf("Enter the port number : ");
    scanf("%d", &port);
    getchar();

    serveraddr.sin_port = htons(port);

    connect(clientsocket,(struct sockaddr*)&serveraddr, sizeof(serveraddr));

    printf("Enter the message to the sever : ");
    fgets(message,sizeof(message),stdin);
    message[strcspn(message, "\n")] = 0;

    send(clientsocket,message,strlen(message),0);
    printf("Message sent to sever");

    recv(clientsocket,rev_msg,sizeof(rev_msg),0);
    printf("Message received from server %s", rev_msg);

    close(clientsocket);
    return 0;
}