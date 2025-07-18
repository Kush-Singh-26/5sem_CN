#include<stdio.h>
#include<stdlib.h>
#define s_size 20

typedef struct{
    char name[s_size];
    int sub_id;
    int age;
} Student;

int main()
{
    Student s1;
    Student *ptr;
    
    printf("Enter the name of student : ");
    scanf("%s", s1.name);
    printf("Enter subject id : ");
    scanf("%d",&s1.sub_id);
    printf("Enter age : ");
    scanf("%d", &s1.age);

    printf("Details Entered are using structure variable :\n");
    printf("Name : %s\n",s1.name);
    printf("Age : %d\n", s1.age);
    printf("Subject ID : %d\n",s1.sub_id);

    ptr = &s1;

    printf("Details Entered are using pointer variable :\n");
    printf("Name : %s\n",ptr->name);
    printf("Age : %d\n", ptr->age);
    printf("Subject ID : %d\n",ptr->sub_id);

    return 0;
}