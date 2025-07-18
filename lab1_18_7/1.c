// WAP to demonstrate call by value and call by reference.

#include<stdio.h>

int call_by_value(int a)
{
    return a * 10;
}

int call_by_reference(int * a)
{
    return *a * 10;
}

int main()
{
    int a;
    printf("Enter value of a : ");
    scanf("%d",&a);

    printf("Call by value : %d\n", call_by_value(a));
    printf("Call by refernence : %d\n", call_by_reference(&a));

    return 0;
}