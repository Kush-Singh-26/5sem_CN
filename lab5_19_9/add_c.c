#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>
int main()
{
int i,sockfd;
struct sockaddr_in sa;
int nums[2];

sockfd = socket(AF_INET, SOCK_DGRAM, 0);

sa.sin_family=AF_INET;
sa.sin_addr.s_addr=inet_addr("127.0.0.1");//loop back ip address
sa.sin_port=htons(6034);


printf("Enter 2 numbers : ");
scanf("%d%d",&nums[0], &nums[1]);

sendto(sockfd, nums, sizeof(nums), 0, (struct sockaddr *)&sa, sizeof(sa));

int result;

int len = sizeof(sa);
int k = recvfrom(sockfd, &result, sizeof(result), 0, (struct sockaddr *)&sa, &len);

printf("Result is : %d\n",result);

close(sockfd);
}