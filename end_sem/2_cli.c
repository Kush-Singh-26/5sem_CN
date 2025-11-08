#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int main() {
    int i, sockfd, choice;
    float num1, num2, result;
    struct sockaddr_in sa;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr("127.0.0.1");
    sa.sin_port = htons(6034);

    i = connect(sockfd, (struct sockaddr *)&sa, sizeof(sa));

    printf("Connected to server.\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        send(sockfd, &choice, sizeof(choice), 0);

        if (choice == 5) {
            printf("Exiting\n");
            break;
        }

        printf("Enter two numbers: ");
        scanf("%f %f", &num1, &num2);

        send(sockfd, &num1, sizeof(num1), 0);
        send(sockfd, &num2, sizeof(num2), 0);

        recv(sockfd, &result, sizeof(result), 0);
        printf("Result = %.2f\n", result);
    }

    close(sockfd);
    return 0;
}
