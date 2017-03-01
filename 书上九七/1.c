#include<stdio.h>
#define N 3
struct student
{
int num;
char name [20];
float score [3];
float aver;
};
void main()
{
	void input(struct student stu[]);
struct student max(struct student stu[]);
void print(struct student stu);
struct student stu[N],*p=stu;
input(p);
print(max(p));
}
void input(struct student stu[])
{
int i;
printf("请输入各学生的信息：\n");
for(i=0;i<N;i++)
{
	scanf("%d%s%f%f%f",&stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);
stu[i].aver=(stu[i]+score[0]+stu[i].score[1]+stu[i].score[2])/3.0;
}
}
struct student max(struct student stu[])
{

int i,m=0;
for(i=0;i<N;i++)
if(stu[i].aver>stu[m].aver)
m=i;
return stu[m];
}
void print(struct student stud)
{
printf("%f%f%f\n %f\n,stud.num,stud.name,stud.score[0],stud.score[1],stud.score[2],stud.aver");}