#include <stdio.h>
#include <string.h>

int main() {
    char frame[50][50], str[50][50];
    char flag[] = "flag";
    char esc[] = "esc";
    int i, k = 0, n;

    strcpy(frame[k++], flag);  
    printf("Enter number of strings: ");
    scanf("%d", &n);
    getchar();  

    printf("Enter strings (one per line):\n");
    for (i = 0; i < n; i++) {
        fgets(str[i], sizeof(str[i]), stdin);
       
        str[i][strcspn(str[i], "\n")] = '\0';
    }

    printf("\n\nYou entered:\n");
    for (i = 0; i < n; i++) {
        puts(str[i]);
    }

    for (i = 0; i < n; i++) {
        if (strcmp(str[i], flag) == 0 || strcmp(str[i], esc) == 0) {
            strcpy(frame[k++], esc);
        }
        strcpy(frame[k++], str[i]);
    }

    strcpy(frame[k++], flag);  

    printf("\n------------------------------\n");
    printf("Byte stuffing at sender side:\n");
    printf("------------------------------\n");
    for (i = 0; i < k; i++) {
        printf("%s\t", frame[i]);
    }
    printf("\n");

    printf("\n------------------------------\n");
    printf("De-Byte stuffing at sender side:\n");
    printf("------------------------------\n");

    char destuffed[50][50];
    int j = 0;
    for(int i =1 ;i<k-1;i++)
    {
        if(strcmp(frame[i], esc) == 0)
            i++;
        strcpy(destuffed[j++], frame[i]);
    }
    for (i = 0; i < j; i++) {
        printf("%s\t", destuffed[i]);
    }
    printf("\n");

    return 0;
}
