// tcp_cli.c - Looping version
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
    int i, sockfd;
    char buf[100];
    struct sockaddr_in sa;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr("127.0.0.1"); // Or server's IP
    sa.sin_port = htons(6034);

    i = connect(sockfd, (struct sockaddr *)&sa, sizeof(sa));

    // Loop for continuous communication
    while(1)
    {
        // --- SENDING ---
        printf("Enter message to send: ");
        // A safer alternative to gets() is fgets()
        // fgets(buf, sizeof(buf), stdin);
        // buf[strcspn(buf, "\n")] = 0; // Remove trailing newline from fgets
        gets(buf); 
        send(sockfd, buf, strlen(buf), 0);

        // Check if the client wants to exit
        if (strcmp(buf, "exit") == 0) {
            printf("Closing connection.\n");
            break;
        }

        // --- RECEIVING ---
        int k = recv(sockfd, buf, 100, 0);
        if (k > 0) {
            buf[k] = '\0';
            printf("Server says: %s\n", buf);
        }
    }

    close(sockfd);
    return 0;
}