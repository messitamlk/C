#include<stdio.h>
struct student{
int num;
char name[20];
char sex;
int age ;
};
struct student stu[3]={{1,"li",'M',18},{2,"zhang",'M',19},{3,"WANG",'F',20}};
void main()
{
struct student *p;
for(p=stu;p<stu+3;p++)

printf("%d%s%c%d\n",p->num,p->name,p->sex,p->age);
}
