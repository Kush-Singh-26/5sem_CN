// tcp_ser.c - Looping version
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h> // For close()

int main()
{
    int sockfd, fd1, length, i;
    char buf[100];
    struct sockaddr_in sa, ca;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = INADDR_ANY; // Listen on all interfaces
    sa.sin_port = htons(6034);

    i = bind(sockfd, (struct sockaddr *)&sa, sizeof(sa));
    printf("Bind successful.\n");

    listen(sockfd, 5);
    printf("Listening for connections...\n");

    length = sizeof(ca);
    fd1 = accept(sockfd, (struct sockaddr *)&ca, &length);
    printf("Connection accepted from client.\n");

    // Loop for continuous communication
    while(1)
    {
        // --- RECEIVING ---
        int k = recv(fd1, buf, 100, 0);
        if (k <= 0) { // If recv returns 0 or -1, client disconnected
            printf("Client disconnected.\n");
            break;
        }
        
        buf[k] = '\0';
        
        // Check if the client wants to exit
        if (strcmp(buf, "exit") == 0) {
            printf("Client sent exit command. Closing connection.\n");
            break;
        }
        
        printf("Client says: %s\n", buf);

        // --- SENDING ---
        printf("Enter reply to send: ");
        gets(buf);
        send(fd1, buf, strlen(buf), 0);
    }

    close(fd1); // Close client-specific socket
    close(sockfd); // Close main listening socket
    return 0;
}