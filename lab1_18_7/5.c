#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int age;
    char name[20];
} Person;

int main()
{
    Person *p = (Person *) malloc(sizeof(Person));

    printf("Enter name : ");
    scanf("%s",p->name);
    printf("Enter age : ");
    scanf("%d",&p->age);

    printf("Details :\n");
    printf("%s\n",p->name);
    printf("%d\n",p->age);
}