# include<stdio.h>
#define N 5
struct student
{
int num;
char name[20];
float score;
};	struct student stu[N]={{1,"zhang",78},{2,"wang",98.5},{3,"li",86},{4,"lin",73.5},{5,"sun",100}};
void main()
{


		struct student*p;
struct student temp;
int i,j,k;
printf("The order is:\n");
for(i=0;i<N-1;i++)
{
	k=i;
for(j=i+1;j<N;j++)
if(stu[j].score>stu[k].score)
k=j;
temp=stu[k];stu[k]=stu[i];stu[i]=temp;
}
for(i=0;i<N;i++)

	printf("%6d%8s%6.2f\n",p->num,p->name,p->score);

}