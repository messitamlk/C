#include<stdio.h>
#include<stdlib.h>//�Ӽ��������ַ�������������͵������ϣ�ֱ������#Ϊֹ
void main()
{
FILE *fp;
char ch,filename[10];
printf("�����������ļ���:");
scanf("%s",filename);
if((fp=fopen(filename,"w"))==NULL)
{printf("�޷��򿪴��ļ���\n");
exit(0);
}
ch=getchar();
printf("������һ��׼���洢�����̵��ַ�����#������");
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
