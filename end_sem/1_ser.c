#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>

int factorial(int n) {
    if(n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    int sockfd, fd1, length, i, choice, num, fact;
    char buf[100], buf1[100];
    struct sockaddr_in sa, ca;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr("127.0.0.1");
    sa.sin_port = htons(6034);

    i = bind(sockfd, (struct sockaddr *)&sa, sizeof(sa));
    printf("test %d %d\n", sockfd, i);

    listen(sockfd, 5);

    length = sizeof(ca);
    fd1 = accept(sockfd, (struct sockaddr *)&ca, &length);
    printf("Client connected.\n");

    while (1) {
        recv(fd1, &choice, sizeof(choice), 0);
        if (choice == 1) {
            recv(fd1, buf, sizeof(buf), 0);
            printf("Client: %s\n", buf);
            strcpy(buf1, "Message received.");
            send(fd1, buf1, strlen(buf1), 0);
        } 
        else if (choice == 2) {
            time_t t = time(NULL);
            strcpy(buf, ctime(&t));
            send(fd1, buf, strlen(buf), 0);
        } 
        else if (choice == 3) {
            recv(fd1, &num, sizeof(num), 0);
            fact = factorial(num);
            send(fd1, &fact, sizeof(fact), 0);
        } 
        else if (choice == 4) {
            printf("Client requested to exit.\n");
            break;
        }
    }

    close(fd1);
    close(sockfd);
}
