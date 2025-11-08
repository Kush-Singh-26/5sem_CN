#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int main() {
    int sockfd, fd1, length, i, choice;
    float num1, num2, result;
    struct sockaddr_in sa, ca;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr("127.0.0.1");
    sa.sin_port = htons(6034);

    i = bind(sockfd, (struct sockaddr *)&sa, sizeof(sa));

    listen(sockfd, 5);
    printf("Server started.\n");

    length = sizeof(ca);
    fd1 = accept(sockfd, (struct sockaddr *)&ca, &length);
    printf("Client connected.\n");

    while (1) {
        recv(fd1, &choice, sizeof(choice), 0);
        if (choice == 5) {
            printf("Exiting\n");
            break;
        }

        recv(fd1, &num1, sizeof(num1), 0);
        recv(fd1, &num2, sizeof(num2), 0);

        switch (choice) {
            case 1: result = num1 + num2; break;
            case 2: result = num1 - num2; break;
            case 3: result = num1 * num2; break;
            case 4: 
                if (num2 == 0)
                    result = 0;  
                else
                    result = num1 / num2;
                break;
            default: result = 0;
        }

        send(fd1, &result, sizeof(result), 0);
    }

    close(fd1);
    close(sockfd);
    return 0;
}
