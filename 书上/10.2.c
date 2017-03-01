#include<stdio.h>
#include<stdlib.h>//将一个磁盘文件复制到另一个磁盘文件中
void main()
{
FILE*in,*out;
char ch,infile[10],outfile[10];
printf("请输入读入文件名：");
scanf("%s",infile);
printf("请输入输出文件名：");
scanf("%s",outfile);
if((in=fopen(infile,"r"))==NULL)
{
printf("无法打开此文件！");
exit(0);
}
if((out=fopen(outfile,"w"))==NULL)
printf("无法打开此文件！");
exit(0);}
while (!feof(in))
{
	ch=fgetc(in);
fputc(ch,out);
putchar(ch);
}
putchar(10);
fclose(in);
fclose(out);
}
