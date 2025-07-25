#include<stdio.h>

typedef unsigned char BYTE;

int main()
{
    unsigned int value=0x11223344; // 4 Byte value

    BYTE a,b,c,d; // to store byte by byte

    a = (value&0xff); // Extract first byte
    b = ((value>>8)&0xff);
    c = ((value>>16)&0xff);
    d = ((value>>24)&0xff);

    /*
    a = (value & 0xFF) = bitwise '&' between value and 11111111 (1, 8 times).
    */

    printf("a = %x\n", a);
    printf("b = %x\n", b);
    printf("c = %x\n", c);
    printf("d = %x\n", d);

    return 0;
}