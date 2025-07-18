#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);

    int *arr = (int*) malloc(sizeof(int) * n);

    printf("Enter %d numbers :",n);
    int sum = 0;

    for(int i =0;i<n;i++)
    {
        scanf("%d",arr+i);
        sum += *(arr+i);
    }

    printf("Sum = %d\n",sum);
    return 0;
}