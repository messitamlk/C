#include<stdio.h>
#include<stdlib.h>//��һ�������ļ����Ƶ���һ�������ļ���
void main()
{
FILE*in,*out;
char ch,infile[10],outfile[10];
printf("����������ļ�����");
scanf("%s",infile);
printf("����������ļ�����");
scanf("%s",outfile);
if((in=fopen(infile,"r"))==NULL)
{
printf("�޷��򿪴��ļ���");
exit(0);
}
if((out=fopen(outfile,"w"))==NULL)
printf("�޷��򿪴��ļ���");
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
