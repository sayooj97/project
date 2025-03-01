#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int server_fd, client_fd, port;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char message[50];

    printf("Enter port number: ");
    scanf("%d", &port);

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    
    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind and listen
    bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_fd, 5);
    printf("\nWaiting for client...\n");

    // Accept connection
    client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len);
    printf("\nClient connected.\n");

    // Receive and respond
    read(client_fd, message, sizeof(message));
    printf("\nClient sent: %s", message);
    write(client_fd, "Message received!", 17);

    close(client_fd);
    close(server_fd);
}
