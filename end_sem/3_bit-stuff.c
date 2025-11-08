#include<stdio.h>
#include<string.h>
int main()
{
    char databits[100];

    printf("Enter data bits : ");
    scanf("%s",databits);

    printf("Data Bits before Bit Stuffing : \n");
    printf("%s",databits);
    char stuffed[150];

    int count = 0;
    int j=0;
    printf("\nData Bits after Bit Stuffing : \n");

    for(int i = 0;i <strlen(databits);i++)
    {
        if(databits[i] == '1')
            count++;
        else count = 0;
        stuffed[j++] = databits[i];
        if(count == 5)
        {
            stuffed[j++] = '0';
            count=0;
        }
    }
    stuffed[j] = '\0'; 
    printf("%s\n", stuffed);

printf("De-Stuffing\n");

char destuffed[100];

count = 0, j=0;

for(int i = 0; i< strlen(stuffed);i++)
{
    if(stuffed[i] == '1') count++;
    else count =0;
    destuffed[j++] = stuffed[i];
    if(count == 5) i++;
}

    printf("%s\n", destuffed);
    return 0;
}