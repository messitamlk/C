#include<stdio.h>
void main()
{
	int a;
printf("请输入");
scanf("%d",&a);
if(a%2!=0&&a%3!=0&&a%5!=0&&a%7!=0&&a%11!=0&&a%13!=0)
printf("这是一个素数！");
else
printf("这不是一个素数！");
}
