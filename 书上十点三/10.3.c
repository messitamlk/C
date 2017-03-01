#include<stdio.h>

#include<stdlib.h>\\从键盘读入若干个字符串，对他们按字母大小的顺序排序，然后把排好的存起来
#include<string.h>
void main()
{
FILE*fp;
char str[3][10],temp[10];
int i,j,k,n=3;
printf("请输入字符：\n");
for(i=0;i<n;i++)
gets(str[i]);
for(i=0;i<n-1;i++)
{
k=i;
for(j=i+1;j<n;j++)
if(strcmp(str[i],str[j])>0)k=j;
if(k!=i)
{
strcpy(temp,str[i]);
strcpy(str[i],str[k]);
strcpy(str[k],temp);
}
}
if((fp=fopen("D:\\CC\\temp\\string.dat","w"))==NULL)
{
}
}
