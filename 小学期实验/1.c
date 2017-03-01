#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#define SNUM 100

typedef struct book_line
{
	int bookno;
	char bookname[30];

	float price;
	char athor[10];
	char isborrowed[5];
	struct book_line *next;
}book;
typedef struct reader_line
{
	int readerno;
	char name[20];
	char sex[10];                
	int age;
	char pro[20];
	int no_borrow;
} reader;


void show_menu(book *head);
void search(book *head);
void bookmange(book *head);
void ment(book *head);
void reade(book *head);
void addbook(book *head);
void daoru(book *head,reader *a);
void daochu(book *head,reader *a);
void liulan(book *head);
void xiugait(book *head);
void sanchut(book *head);
void anbianhao(book *head);
void anshuming(book *head);
void anzuozhe(book *head);
void jieshu(book *head,reader *a);
void huanshu(book *head);
void xinzheng(reader *a);
void liuland(reader *a);
void xiugair(reader *a);
void sanchu(reader *a);
void tuchu(book *head,reader *a);

#define N 1000
	reader a[N];


#define LEN (book *)malloc(sizeof(book))



int main(void)
{
	book *head;
	head = LEN;
	head->next = NULL;
	show_menu(head);

	
}             


void show_menu(book *head)
{
	int chioce;
	system("cls");

	printf("		ͼ����Ĺ�����Ϣϵͳ\n");
	printf("	-------------------------------------\n");
	printf("		  1.ͼ����Ϣ��ѯ\n");
	printf("		  2.ͼ����Ϣ����\n");
	printf("		  3.������Ϣ����\n");
	printf("		  4.��        ��\n");
	printf("		  5.��        ��\n");
	printf("		  6.ϵ ͳ  �� ��\n");
	printf("		  0.�� ��  ϵ ͳ\n");
	printf("	-------------------------------------\n");
	printf("\n");
	printf("	��ѡ������ʹ�õĹ���<0-6>:");
	scanf("%d", &chioce);
	getchar();
	switch (chioce)
	{
	case 1:search(head); break;
	case 2:bookmange(head); break;
	case 3:reade(head); break;
	case 4:jieshu(head,a); break;
	case 5:huanshu(head); break;
	case 6:ment(head); break;
	case 0:tuchu(head,a);; break;
	default:printf("�������");
	}
}


void search(book *head)
{
	int a;
	system("cls");

	printf("	-------------------------------------\n");
	printf("		  1.��ͼ���Ų�ѯ\n");
	printf("		  2.�� �� �� �� ѯ\n");
	printf("		  3.�� �� �� �� ѯ\n");
	printf("		  0.������һ���˵�\n");
	printf("	-------------------------------------\n");
	printf("\n");
	printf("	��ѡ������ʹ�õĹ���<0-3>:");
	scanf("%d", &a);
	switch (a)
	{
	case 1:anbianhao(head); break;
	case 2:anshuming(head); break;
	case 3:anzuozhe(head); break;
	case 0:show_menu(head); break;
	default:printf("�������");
	}
}

void bookmange(book *head)
{
	int a;
	system("cls");
	fflush(stdin);


	printf("			ͼ����Ϣ����\n");
	printf("	-------------------------------------\n");
	printf("		  1.�������ͼ����Ϣ\n");
	printf("		  2.��   ��  ͼ   ��\n");
	printf("		  3.�� �� ͼ �� ��Ϣ\n");
	printf("		  4.ɾ �� ͼ �� ��Ϣ\n");
	printf("		  5.��            ��\n");
	printf("		  0.���� ��һ�� �˵�\n");
	printf("	-------------------------------------\n");
	printf("\n");
	printf("	��ѡ������ʹ�õĹ���<0-5>:");
	scanf("%d", &a);
	getchar();
	switch (a)
	{
	case 1: liulan(head); break;
	case 2:addbook(head); break;
	case 3:xiugait(head); break;
	case 4:sanchut(head); break;
	case 5:; break;
	case 0:show_menu(head); break;
	default:printf("�������");

	}
}

void reade(book *head)
{
	int choose;
	system("cls");

	printf("			������Ϣ����\n");
	printf("	-------------------------------------\n");
	printf("		  1.������ж�����Ϣ\n");
	printf("		  2.��   ��  ��   ��\n");
	printf("		  3.�� �� �� �� ��Ϣ\n");
	printf("		  4.ɾ �� �� �� ��Ϣ\n");
	printf("		  5.��            ��\n");
	printf("		  0.���� ��һ�� �˵�\n");
	printf("	-------------------------------------\n");
	printf("\n");
	printf("	��ѡ������ʹ�õĹ���<0-5>:");
	scanf("%d", &choose);
	switch (choose)
	{
	case 1:liuland(a);reade(head);; break;
	case 2:xinzheng(a);reade(head);; break;
	case 3:xiugair(a);reade(head); break;
	case 4:sanchu(a);reade(head); break;
	case 5:; break;
	case 0:show_menu(head); break;
	default:printf("�������");
	}
}

void ment(book *head)
{
	int choose;
	system("cls");

	printf("			ϵͳ����\n");
	printf("	-------------------------------------\n");
	printf("		  1.�� �� �� �� ��\n");
	printf("		  2.�� �� �� �� ��\n");
	printf("		  0.������һ���˵�\n");
	printf("	-------------------------------------\n");
	printf("\n");
	printf("	��ѡ������ʹ�õĹ���<0-2>:");
	scanf("%d", &choose);
	switch (choose)
	{
	case 0:show_menu(head); break;
	case 1:daoru(head,a); break;
	case 2:daochu(head,a); break;
	default:printf("�������");
	}
}

void addbook(book *head)
{
	
	while (1)
	{

		int a;
		book *q;
		system("cls");
		q = LEN;
		printf("��������ı��(����0�˳�)��");
		scanf("%d", &a);
		getchar();
		if (a == 0)
		{
			bookmange(head);
		}
		q->bookno = a;
		printf("������������");
		gets(q->bookname);
		printf("������������ߣ�");
		gets(q->athor);
		printf("��������ļ۸�");
		scanf("%f", &q->price);
		getchar();
		printf("���������Ƿ񱻽����");
		gets(q->isborrowed);
		q->next=head->next;
		head->next = q;	
	}
}

void liulan(book *head)
{
	book *p;
	system("cls");
	for (p = head->next; p != NULL; p = p->next)
	{
		printf("ͼ���ţ�%d\n", p->bookno);
		printf("ͼ�����֣�");
		puts(p->bookname);
		printf("���ۣ�%.2f\n", p->price);
		printf("����������");
		puts(p->athor);
		printf("����״̬��%s\n", p->isborrowed);

		printf("\n\n");
	
	
	}
    system("pause");
	
	printf("�����������һ�˵�");
	getchar();
	bookmange(head);

}
void xiugait(book *head)
{  
	int b; 
	book *p;
	  system("cls");
	p=head->next;
	printf("�������޸�ͼ���ţ�");
	scanf("%d",&b);
	getchar();
	while(p!=NULL&&p->bookno!=b)
	{
		p=p->next;
	}
	if(p==NULL)
	{
		printf("Ī���Ȿ�飡��������˳�����");
		getchar();
		bookmange(head);
	}
  
	{
	    
		printf("�������µı�ţ�");
		scanf("%d",&p->bookno);
		getchar();
		printf("�������µ�������");
		gets(p->bookname);
		printf("�������µ����ߣ�");
		gets(p->athor);
		printf("�������µļ۸�");
		scanf("%f",&p->price);
		getchar();
		bookmange(head);


	}

}    
void sanchut(book *head)
{	
	int c;
	book *t ,*q;
	system("cls");
	t=head;
	q=t->next;
	printf("��������Ҫɾ�����Ǳ���ı�ţ�");
	scanf("%d",&c);
	getchar();
	while(q->next!=NULL&&q->bookno!=c)
	{	
		t=t->next;
		q=t->next;
	}
	if(q->next==NULL)
	{
		printf("Ī���Ȿ�飡��������˳�����");
		getchar();
	bookmange(head);
	
	}
	    t->next=q->next;
	printf("ɾ���ɹ���");
	printf("�����������һ�˵�");
	free(q);
	getchar();

	bookmange(head);

}
void anbianhao(book *head)
{	
	int d;
	book *j;
	system("cls");
	j=head;

	printf("��������ı�ţ�\n");
	scanf("%d",&d);
	while(j->next!=NULL&&j->bookno!=d)
		{	j=j->next;}
		
	if(j->next==NULL)
	{
		printf("Ī���Ȿ�飡��������˳�����");
		printf("�����������һ�˵�");
		system("pause");
		getchar();
		search(head);
	}

	printf("ͼ���ţ�%d\n",j->bookno);
	printf("ͼ������%s\n",j->bookname);
	printf("ͼ�����ߣ�%s\n",j->athor);
	printf("ͼ��۸�%f\n",j->price);
	printf("�Ƿ񱻽��ģ�%s\n",j->isborrowed);
	printf("�����������һ�˵�");
	system("pause");
	getchar();
	search(head);
}
void anshuming(book *head)
{
	char d [20];
	book *j;
	system("cls");
	j=head;
	fflush(stdin);
	printf("������������\n");
	gets(d);
	while(j->next!=NULL&&strcmp(d,j->bookname))
		{	j=j->next;
		}
	if(j->next==NULL)
	{
		printf("Ī���Ȿ�飡��������˳�����");
	printf("�����������һ�˵�");
	system("pause");
	getchar();
	search(head);
	}

	printf("ͼ���ţ�%d\n",j->bookno);
	printf("ͼ������%s\n",j->bookname);
	printf("ͼ�����ߣ�%s\n",j->athor);
	printf("ͼ��۸�%f\n",j->price);
	printf("�Ƿ񱻽��ģ�%s\n",j->isborrowed);
	printf("�����������һ�˵�");
	system("pause");
	getchar();
	search(head);
}
void anzuozhe(book *head)
{
	
	
	char d[20];
	book *j;
	system("cls");
	j=head;
	fflush(stdin);
	printf("���������ߣ�\n");
	gets(d);
	while(j->next!=NULL&&strcmp(d,j->bookname))
		{	j=j->next;
		}
	if(j->next==NULL)
	{
		printf("Ī���Ȿ�飡��������˳�����");
		getchar();
		printf("�����������һ�˵�");
		system("pause");
		getchar();
		search(head);
	}

	printf("ͼ���ţ�%d\n",j->bookno);
	printf("ͼ������%s\n",j->bookname);
	printf("ͼ�����ߣ�%s\n",j->athor);
	printf("ͼ��۸�%f\n",j->price);
	printf("�Ƿ񱻽��ģ�%s\n",j->isborrowed);
	printf("�����������һ�˵�");
	system("pause");
	getchar();
	search(head);
}
void jieshu(book *head,reader *a)
{
	int d,k,i;
	
	book *j;
	system("cls");
	j=head->next;
	printf("����������ţ�\n");

	scanf("%d",&d);
	while(j!=NULL)
	{	
		if(j->bookno!=d)
			j=j->next;
		else
			break;
	}	
	
	if(j==NULL)
	{
		printf("Ī���Ȿ�飡��������˳�����\n");
		printf("�����������һ�˵�");
		system("pause");
		show_menu(head);
	
	}
	else 
	{
		strcpy(j->isborrowed,'yes');	
		printf("�����������ѧ�ţ�");
		scanf("%d",&k);
		for(i=0;a[i].readerno!=d;i++);
		if(a[i].readerno==d)
		{a[i].no_borrow++;}

		printf("����ɹ���");
		printf("�����������һ�˵�");
		system("pause");
		getchar();
		show_menu(head);
	}
	
}
void huanshu(book *head)
{
	int d;
	
	book *j;
	system("cls");
	j=head->next;
	printf("����������ţ�\n");
	scanf("%d",&d);
	getchar();
	while(j!=NULL)
	{	
		if(j->bookno!=d)
		j=j->next;
		else
			break;
	}	
	
	if(j==NULL)
	{
		printf("Ī���Ȿ�飡��������˳�����\n");
		printf("�����������һ�˵�");
		system("pause");
		show_menu(head);
	
	}
	else 
	{
		strcpy(j->isborrowed,'no');		
		printf("����ɹ���");
		printf("�����������һ�˵�");
		system("pause");
		getchar();
		show_menu(head);
	}
	
}
void xinzheng(reader *a)
{	int i;
	char t;
	system("cls");
	for(i=0;i<=N;i++)
	{
		printf("����������(����0������һ��)");
		scanf("%s",&t);
		if(t!='0')
		{
			
		*a[i].name = t;
		printf("������ѧ�ţ�");
		scanf("%d",&a[i].readerno);
		printf("���������䣺");
		scanf("%d",&a[i].age);
		printf("�������Ա�");
		scanf("%s",&a[i].sex);
		printf("������Ժϵ��");
		scanf("%s",&a[i].pro);
		printf("�������ѽ�������");
		scanf("%d",&a[i].no_borrow);

		printf("�����ɹ���");
		
		}
		else
			break;
	}	
}
void liuland(reader *a)
{	
	int i;
	system("cls");
	for(i=0;i<N;i++)
	{		if(a[i].age!=0)
			{
		printf("������%s\n",a[i].name);
		printf("�Ա�%s\n",a[i].sex);
		printf("���䣺%d\n",a[i].age);
		printf("��������%d\n",a[i].no_borrow);
		printf("Ժϵ��%s\n",a[i].pro);
		printf("ѧ�ţ�%d\n",a[i].readerno);
		}
	
	}
		printf("�����������һ�˵�");
		system("pause");
		getchar();
		
}
void xiugair(reader *a)
{	
	int i,d;
	system("cls");
	printf("�������޸�ѧ���ı�ţ�");
	scanf("%d",&d);
	for(i=0;a[i].readerno!=d;i++)
	{}
	if(a[i].readerno==d)
	{
		printf("�������µ�����:");
		scanf("%s",&a[i].name);
		printf("�������µ�Ժϵ:");
		scanf("%s",&a[i].pro);
		printf("�������µ��Ա�:");
		scanf("%s",&a[i].sex);
		printf("�������µ�����:");
		scanf("%d",&a[i].age);
		printf("�������µĽ�����:");
		scanf("%d",&a[i].no_borrow);
		printf("�������µ�ѧ�����:");
		scanf("%d",&a[i].readerno);
		printf("�޸���ɣ������������");
		system("pause");
	}
		
}
void sanchu(reader *a)
{	
	int i,j,d;
	system("cls");
	printf("������ɾ��ѧ���ı�ţ�");
	scanf("%d",&d);
	for(i=0;a[i].readerno!=d;i++)
	{}
	if(a[i].readerno==d)
	{
		for(j=0;a[j].age!=0;j++)
		a[i]=a[i+1];
		i++;
		printf("ɾ����ɣ������������");
		system("pause");
	}	
}
void daoru(book *head,reader *a)
{	

	FILE *fp;
	system("cls");
	fp = fopen("a1","wb");
	
	fwrite(head,sizeof(struct book_line),1,fp);
	fwrite(a,sizeof(struct reader_line),1,fp);
	fclose(fp);
	printf("����ɹ���\n");
	printf("�����������һ�˵�");
	system("pause");
	getchar();
	ment(head);

}
void daochu(book *head,reader *a)
{	
	FILE *fp;
	system("cls");
	fp = fopen("a1","wb");
	fread(head,sizeof(struct book_line),1,fp);
	fread(a,sizeof(struct reader_line),1,fp);
	fclose(fp);
	printf("�����ɹ���\n");
	printf("�����������һ�˵�");
	system("pause");
	getchar();
	ment(head);

}
void tuchu(book *head,reader *a)
{	
	char ch[5];
	system("cls");
	printf("�Ƿ���Ҫ����(yes\\no)��\n");
	gets(ch);
	if(!strcmp(ch,"yes"))
	{
		FILE *fp;
	system("cls");
	fp = fopen("a1","wb");
	fwrite(head,sizeof(struct book_line),1,fp);
	fwrite(a,sizeof(struct reader_line),1,fp);
	fclose(fp);
	
	printf("����ɹ���\n");
	system("pause");
		exit(0);

	}
	else
	{
		system("pause");
		exit(0);
	}


}