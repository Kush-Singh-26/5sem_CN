#include<stdio.h>

int main()
{
    unsigned int x = 0x76513210;

    char *c = (char*) &x; 

    printf("c is : 0x%x\n", *c);
    if(*c == 0x10)
        printf("Architecture is little endian.\n");
    else
        printf("Architecture is big endian.\n");

    return 0;
}