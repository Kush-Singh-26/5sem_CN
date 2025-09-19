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
char buf[100],buf1[100];
struct sockaddr_in sa,ca;

sockfd=socket(AF_INET,SOCK_DGRAM,0);

sa.sin_family=AF_INET;
sa.sin_addr.s_addr=inet_addr("127.0.0.1");
sa.sin_port=htons(6034);

i=bind(sockfd,(struct sockaddr *)&sa,sizeof(sa));
printf("test %d%d\n",sockfd,i);

length = sizeof(ca); 
int k = recvfrom(sockfd, buf, 100, 0, (struct sockaddr *)&ca, &length);
buf[k] = '\0';
printf("%s\n", buf);
int flag = 0;
int j = strlen(buf) - 1;
int m =0;
while(i<j)
{
    if(buf[m] != buf[j])
    {
        flag = 1;
        break;
    }
    m++;
    j--;
}

if(flag)
    strcpy(buf1,"Not a palindrome.");
else
    strcpy(buf1,"It is a palindrome.");

sendto(sockfd, buf1, strlen(buf1), 0, (struct sockaddr *)&ca, length);
close(sockfd);

return 0;
}