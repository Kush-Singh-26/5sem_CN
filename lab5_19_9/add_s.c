#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>
int main()
{
int sockfd,length,i;
struct sockaddr_in sa,ca;

sockfd=socket(AF_INET,SOCK_DGRAM,0);

sa.sin_family=AF_INET;
sa.sin_addr.s_addr=inet_addr("127.0.0.1");
sa.sin_port=htons(6034);

i=bind(sockfd,(struct sockaddr *)&sa,sizeof(sa));
printf("test %d%d\n",sockfd,i);

int nums[2];

length = sizeof(ca); 
int k = recvfrom(sockfd, nums, sizeof(nums), 0, (struct sockaddr *)&ca, &length);

printf("Number received are : %d and %d.\n",nums[0],nums[1]);
int result = nums[0] + nums[1];

sendto(sockfd, &result, sizeof(result), 0, (struct sockaddr *)&ca, length);
close(sockfd);

return 0;
}