#include<stdio.h>

int main()
{
    unsigned int x = 0x76513210;

    char *c = (char*) &x; 

    printf("c is : 0x%x\n", *c);
    if(*c == 0x10)
    {
        printf("Architecture is little endian.\n");
    }
    else
    {
        printf("Architecture is big endian.\n");
    }

    printf("Address = %p and content is  0x%x\n", c+0, *(c + 0x0));
    printf("Address = %p and content is  0x%x\n", c+1, *(c + 0x1));
    printf("Address = %p and content is  0x%x\n", c+2, *(c + 0x2));
    printf("Address = %p and content is  0x%x\n", c+3, *(c + 0x3));

    return 0;
}