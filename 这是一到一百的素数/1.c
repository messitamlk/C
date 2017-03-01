#include<stdio.h>
void main()
{int i,j,k;
k=0;

for(i=1;i<=100;i++)
for(j=2;j<i;j++)
{
	if(i%j==0)break;
if(j+1==i)
{
printf("%d ",i);
k++;
if(k%5==0)
printf("\n");

}

}
printf("2 ");
} 