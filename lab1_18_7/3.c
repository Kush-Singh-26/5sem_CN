#include<stdio.h>
#include<string.h>
#define s_size 20

typedef struct{
    char name[s_size];
    int roll;
    char state[s_size];
    int age;
} student;

int main()
{
    student s1;

    printf("Enter the name of student : ");
    scanf("%s", s1.name);
    printf("Enter roll number : ");
    scanf("%d",&s1.roll);
    printf("Enter state : ");
    scanf("%s", s1.state);
    printf("Enter age : ");
    scanf("%d", &s1.age);

    printf("Details Entered are :\n");
    printf("Name : %s\n",s1.name);
    printf("Age : %d\n", s1.age);
    printf("State : %s\n",s1.state);
    printf("Roll : %d\n",s1.roll);

    return 0;
}