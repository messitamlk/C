#include<stdio.h>
#include<stdlib.h>//从键盘输入字符，逐个把他们送到磁盘上，直到出现#为止
void main()
{
FILE *fp;
char ch,filename[10];
printf("请输入所用文件名:");
scanf("%s",filename);
if((fp=fopen(filename,"w"))==NULL)
{printf("无法打开此文件！\n");
exit(0);
}
ch=getchar();
printf("请输入一个准备存储到磁盘的字符串以#结束：");
ch=getchar();
while(ch!='#')
{
fputc(ch,fp);
putchar(ch);
ch=getchar();
}
fclose(fp);
putchar(10);
}
