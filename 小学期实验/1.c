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

	printf("		图书借阅管理信息系统\n");
	printf("	-------------------------------------\n");
	printf("		  1.图书信息查询\n");
	printf("		  2.图书信息管理\n");
	printf("		  3.读者信息管理\n");
	printf("		  4.借        书\n");
	printf("		  5.还        书\n");
	printf("		  6.系 统  管 理\n");
	printf("		  0.退 出  系 统\n");
	printf("	-------------------------------------\n");
	printf("\n");
	printf("	请选择您想使用的功能<0-6>:");
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
	default:printf("输入错误！");
	}
}


void search(book *head)
{
	int a;
	system("cls");

	printf("	-------------------------------------\n");
	printf("		  1.按图书编号查询\n");
	printf("		  2.按 书 名 查 询\n");
	printf("		  3.按 作 者 查 询\n");
	printf("		  0.返回上一级菜单\n");
	printf("	-------------------------------------\n");
	printf("\n");
	printf("	请选择您想使用的功能<0-3>:");
	scanf("%d", &a);
	switch (a)
	{
	case 1:anbianhao(head); break;
	case 2:anshuming(head); break;
	case 3:anzuozhe(head); break;
	case 0:show_menu(head); break;
	default:printf("输入错误！");
	}
}

void bookmange(book *head)
{
	int a;
	system("cls");
	fflush(stdin);


	printf("			图书信息管理\n");
	printf("	-------------------------------------\n");
	printf("		  1.浏览所有图书信息\n");
	printf("		  2.新   增  图   书\n");
	printf("		  3.修 改 图 书 信息\n");
	printf("		  4.删 除 图 书 信息\n");
	printf("		  5.排            序\n");
	printf("		  0.返回 上一级 菜单\n");
	printf("	-------------------------------------\n");
	printf("\n");
	printf("	请选择您想使用的功能<0-5>:");
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
	default:printf("输入错误！");

	}
}

void reade(book *head)
{
	int choose;
	system("cls");

	printf("			读者信息管理\n");
	printf("	-------------------------------------\n");
	printf("		  1.浏览所有读者信息\n");
	printf("		  2.新   增  读   者\n");
	printf("		  3.修 改 读 者 信息\n");
	printf("		  4.删 除 读 者 信息\n");
	printf("		  5.排            序\n");
	printf("		  0.返回 上一级 菜单\n");
	printf("	-------------------------------------\n");
	printf("\n");
	printf("	请选择您想使用的功能<0-5>:");
	scanf("%d", &choose);
	switch (choose)
	{
	case 1:liuland(a);reade(head);; break;
	case 2:xinzheng(a);reade(head);; break;
	case 3:xiugair(a);reade(head); break;
	case 4:sanchu(a);reade(head); break;
	case 5:; break;
	case 0:show_menu(head); break;
	default:printf("输入错误！");
	}
}

void ment(book *head)
{
	int choose;
	system("cls");

	printf("			系统管理\n");
	printf("	-------------------------------------\n");
	printf("		  1.导 出 到 文 件\n");
	printf("		  2.从 文 件 导 入\n");
	printf("		  0.返回上一级菜单\n");
	printf("	-------------------------------------\n");
	printf("\n");
	printf("	请选择您想使用的功能<0-2>:");
	scanf("%d", &choose);
	switch (choose)
	{
	case 0:show_menu(head); break;
	case 1:daoru(head,a); break;
	case 2:daochu(head,a); break;
	default:printf("输入错误！");
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
		printf("请输入书的编号(输入0退出)：");
		scanf("%d", &a);
		getchar();
		if (a == 0)
		{
			bookmange(head);
		}
		q->bookno = a;
		printf("请输入书名：");
		gets(q->bookname);
		printf("请输入书的作者：");
		gets(q->athor);
		printf("请输入书的价格：");
		scanf("%f", &q->price);
		getchar();
		printf("请输入书是否被借出：");
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
		printf("图书编号：%d\n", p->bookno);
		printf("图书名字：");
		puts(p->bookname);
		printf("单价：%.2f\n", p->price);
		printf("作者姓名：");
		puts(p->athor);
		printf("借阅状态：%s\n", p->isborrowed);

		printf("\n\n");
	
	
	}
    system("pause");
	
	printf("任意键返回上一菜单");
	getchar();
	bookmange(head);

}
void xiugait(book *head)
{  
	int b; 
	book *p;
	  system("cls");
	p=head->next;
	printf("请输入修改图书编号：");
	scanf("%d",&b);
	getchar();
	while(p!=NULL&&p->bookno!=b)
	{
		p=p->next;
	}
	if(p==NULL)
	{
		printf("莫得这本书！按任意键退出》》");
		getchar();
		bookmange(head);
	}
  
	{
	    
		printf("请输入新的编号：");
		scanf("%d",&p->bookno);
		getchar();
		printf("请输入新的书名：");
		gets(p->bookname);
		printf("请输入新的作者：");
		gets(p->athor);
		printf("请输入新的价格：");
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
	printf("请输入您要删除的那本书的编号：");
	scanf("%d",&c);
	getchar();
	while(q->next!=NULL&&q->bookno!=c)
	{	
		t=t->next;
		q=t->next;
	}
	if(q->next==NULL)
	{
		printf("莫得这本书！按任意键退出》》");
		getchar();
	bookmange(head);
	
	}
	    t->next=q->next;
	printf("删除成功！");
	printf("任意键返回上一菜单");
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

	printf("请输入书的编号：\n");
	scanf("%d",&d);
	while(j->next!=NULL&&j->bookno!=d)
		{	j=j->next;}
		
	if(j->next==NULL)
	{
		printf("莫得这本书！按任意键退出》》");
		printf("任意键返回上一菜单");
		system("pause");
		getchar();
		search(head);
	}

	printf("图书编号：%d\n",j->bookno);
	printf("图书名：%s\n",j->bookname);
	printf("图书作者：%s\n",j->athor);
	printf("图书价格：%f\n",j->price);
	printf("是否被借阅：%s\n",j->isborrowed);
	printf("任意键返回上一菜单");
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
	printf("请输入书名：\n");
	gets(d);
	while(j->next!=NULL&&strcmp(d,j->bookname))
		{	j=j->next;
		}
	if(j->next==NULL)
	{
		printf("莫得这本书！按任意键退出》》");
	printf("任意键返回上一菜单");
	system("pause");
	getchar();
	search(head);
	}

	printf("图书编号：%d\n",j->bookno);
	printf("图书名：%s\n",j->bookname);
	printf("图书作者：%s\n",j->athor);
	printf("图书价格：%f\n",j->price);
	printf("是否被借阅：%s\n",j->isborrowed);
	printf("任意键返回上一菜单");
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
	printf("请输入作者：\n");
	gets(d);
	while(j->next!=NULL&&strcmp(d,j->bookname))
		{	j=j->next;
		}
	if(j->next==NULL)
	{
		printf("莫得这本书！按任意键退出》》");
		getchar();
		printf("任意键返回上一菜单");
		system("pause");
		getchar();
		search(head);
	}

	printf("图书编号：%d\n",j->bookno);
	printf("图书名：%s\n",j->bookname);
	printf("图书作者：%s\n",j->athor);
	printf("图书价格：%f\n",j->price);
	printf("是否被借阅：%s\n",j->isborrowed);
	printf("任意键返回上一菜单");
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
	printf("请输入借书编号：\n");

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
		printf("莫得这本书！按任意键退出》》\n");
		printf("任意键返回上一菜单");
		system("pause");
		show_menu(head);
	
	}
	else 
	{
		strcpy(j->isborrowed,'yes');	
		printf("请输入借书人学号：");
		scanf("%d",&k);
		for(i=0;a[i].readerno!=d;i++);
		if(a[i].readerno==d)
		{a[i].no_borrow++;}

		printf("借书成功！");
		printf("任意键返回上一菜单");
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
	printf("请输入借书编号：\n");
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
		printf("莫得这本书！按任意键退出》》\n");
		printf("任意键返回上一菜单");
		system("pause");
		show_menu(head);
	
	}
	else 
	{
		strcpy(j->isborrowed,'no');		
		printf("还书成功！");
		printf("任意键返回上一菜单");
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
		printf("请输入姓名(输入0返回上一级)");
		scanf("%s",&t);
		if(t!='0')
		{
			
		*a[i].name = t;
		printf("请输入学号：");
		scanf("%d",&a[i].readerno);
		printf("请输入年龄：");
		scanf("%d",&a[i].age);
		printf("请输入性别：");
		scanf("%s",&a[i].sex);
		printf("请输入院系：");
		scanf("%s",&a[i].pro);
		printf("请输入已借书数：");
		scanf("%d",&a[i].no_borrow);

		printf("新增成功！");
		
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
		printf("姓名：%s\n",a[i].name);
		printf("性别：%s\n",a[i].sex);
		printf("年龄：%d\n",a[i].age);
		printf("借书数：%d\n",a[i].no_borrow);
		printf("院系：%s\n",a[i].pro);
		printf("学号：%d\n",a[i].readerno);
		}
	
	}
		printf("任意键返回上一菜单");
		system("pause");
		getchar();
		
}
void xiugair(reader *a)
{	
	int i,d;
	system("cls");
	printf("请输入修改学生的编号：");
	scanf("%d",&d);
	for(i=0;a[i].readerno!=d;i++)
	{}
	if(a[i].readerno==d)
	{
		printf("请输入新的姓名:");
		scanf("%s",&a[i].name);
		printf("请输入新的院系:");
		scanf("%s",&a[i].pro);
		printf("请输入新的性别:");
		scanf("%s",&a[i].sex);
		printf("请输入新的年龄:");
		scanf("%d",&a[i].age);
		printf("请输入新的借书数:");
		scanf("%d",&a[i].no_borrow);
		printf("请输入新的学生编号:");
		scanf("%d",&a[i].readerno);
		printf("修改完成！按任意键返回");
		system("pause");
	}
		
}
void sanchu(reader *a)
{	
	int i,j,d;
	system("cls");
	printf("请输入删除学生的编号：");
	scanf("%d",&d);
	for(i=0;a[i].readerno!=d;i++)
	{}
	if(a[i].readerno==d)
	{
		for(j=0;a[j].age!=0;j++)
		a[i]=a[i+1];
		i++;
		printf("删除完成！按任意键返回");
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
	printf("导入成功！\n");
	printf("任意键返回上一菜单");
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
	printf("导出成功！\n");
	printf("任意键返回上一菜单");
	system("pause");
	getchar();
	ment(head);

}
void tuchu(book *head,reader *a)
{	
	char ch[5];
	system("cls");
	printf("是否需要保存(yes\\no)？\n");
	gets(ch);
	if(!strcmp(ch,"yes"))
	{
		FILE *fp;
	system("cls");
	fp = fopen("a1","wb");
	fwrite(head,sizeof(struct book_line),1,fp);
	fwrite(a,sizeof(struct reader_line),1,fp);
	fclose(fp);
	
	printf("保存成功！\n");
	system("pause");
		exit(0);

	}
	else
	{
		system("pause");
		exit(0);
	}


}