/*图书名称模糊查询，排序，文件导出导入*/
#include "stdio.h"
#include "stdlib.h"

typedef struct book_line
{
	int no_book;
	char name_book[20];
	float price;
	char name_aurthor[20];
	char state;            //是否借出，借出为Y
	int no_reader;
	struct book_line *next;
}book;
typedef struct reader_line
{
	int no_reader2;
	char name_reader[20];
	char sex[10];                
	int age;
	char pro[20];
	int no_borrow;
}reader;

#define LEN (book *)malloc(sizeof(book))
#define N 1000

book *head;
reader read[N];
int readnum = 0;

void show_menu(book *head, reader *read);     //主菜单
void inquiry(book *head, reader *read);       //查询菜单
void manage_book(book *head, reader *read);   //图书管理菜单
void manage_reader(book *head, reader *read); //读者查询菜单
void borrow(book *head, reader *read);        //借书
void back(book *head, reader *read);          //还书
void manage_system(book *head, reader *read); //系统管理菜单
void end(book *head, reader *read);           


int main(void)
{
	head = LEN;
	head->next = NULL;
	show_menu(head,read);
}

void show_menu(book *head, reader *read)
{
	system("cls");
	int choose;

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
	scanf("%d", &choose);
	getchar();
	while (1)
	{

		switch (choose)
		{
		case 0:end(head,read);
			break;
		case 1: inquiry(head, read);
			break;
		case 2:manage_book(head, read);
			break;
		case 3:manage_reader(head, read);
			break;
		case 4:borrow(head, read);
			break;
		case 5:back(head, read);
			break;
		case 6:manage_system(head, read);
			break;
		}
		if (choose < 0 || choose>6)
		{
			printf("输入错误，请输入0-6\n");
			scanf("%d", &choose);
			getchar();
		}
	}
}


//图书信息查询
void inquiry_nobook(book *head, reader *read);       //按图书编号查询
void inquiry_namebook(book *head, reader *read);     //按图书名称查询
void inquiry_nameaurthor(book *head, reader *read);  //按作者姓名查询

void inquiry(book *head, reader *read)
{
	system("cls");
	int choose;

	printf("			图书查询\n");
	printf("	-------------------------------------\n");
	printf("		  1.按图书编号查询\n");
	printf("		  2.按 书 名 查 询\n");
	printf("		  3.按 作 者 查 询\n");
	printf("		  0.返回上一级菜单\n");
	printf("	-------------------------------------\n");
	printf("\n");
	printf("	请选择您想使用的功能<0-3>:");
	scanf("%d", &choose);
	getchar();
	while (1)
	{
		switch (choose)
		{
		case 0:show_menu(head, read);
			break;
		case 1:inquiry_nobook(head, read);
			break;
		case 2:inquiry_namebook(head, read);
			break;
		case 3:inquiry_nameaurthor(head, read);
			break;
		}
		if (choose < 0 || choose>3)
		{
			printf("输入错误，请输入0-3\n");
			scanf("%d", &choose);
			getchar();
		}
	}
}
void inquiry_nobook(book *head, reader *read)
{
	system("cls");
	printf("			查询图书信息\n");
	printf("	-------------------------------------\n");
	int num, judge;
	book *p;

	printf("输入需要查询的图书编号（0返回上一菜单）：");
	scanf("%d", &num);
	getchar();
	while (1)
	{
		if (num == 0)
			inquiry(head, read);
		else
		{
			judge = 1;         //判断图书是否存在
			for (p = head->next; p != NULL; p = p->next)
			{
				if (p->no_book == num)
				{
					judge = 0;
					printf("图书编号：%d\n", p->no_book);
					printf("图书名字：");
					puts(p->name_book);
					printf("单价：%.2f\n", p->price);
					printf("作者姓名：");
					puts(p->name_aurthor);
					printf("借阅状态：%c\n", p->state);
					printf("读者编号：%d", p->no_reader);
					printf("\n");
					break;
				}
			}
			if (judge == 1)
			{
				printf("未找到图书，重新输入（0返回上一菜单）：");
				scanf("%d", &num);
				getchar();
			}
			else
			{
				printf("输入需要查询的图书编号（0返回上一菜单）：");
				scanf("%d", &num);
				getchar();
			}
		}
	}
}
void inquiry_namebook(book *head, reader *read)
{
	system("cls");
	printf("			查询图书信息\n");
	printf("	-------------------------------------\n");
	int judge;
	char name[20];
	book *p;

	printf("输入需要查询的图书名称（0返回上一菜单）：");
	gets(name);
	while (1)
	{
		if (!strcmp(name, "0"))
			inquiry(head, read);
		else
		{
			judge = 1;              //判断图书是否存在
			for (p = head->next; p != NULL; p = p->next)
			{
				if (!strcmp(p->name_book, name))
				{
					judge = 0;
					printf("图书编号：%d\n", p->no_book);
					printf("图书名字：");
					puts(p->name_book);
					printf("单价：%.2f\n", p->price);
					printf("作者姓名：");
					puts(p->name_aurthor);
					printf("借阅状态：%c\n", p->state);
					printf("读者编号：%d", p->no_reader);
					printf("\n");
					break;
				}
			}
			if (judge == 1)
			{
				printf("未找到图书，重新输入（0返回上一菜单）：");
				gets(name);
			}
			else
			{
				printf("输入需要查询的图书名称（0返回上一菜单）：");
				gets(name);
			}
		}
	}
}
void inquiry_nameaurthor(book *head, reader *read)
{
	system("cls");
	printf("			查询图书信息\n");
	printf("	-------------------------------------\n");
	int judge;
	char name[20];
	book *p;

	printf("输入需要查询的作者名称（0返回上一菜单）：");
	gets(name);
	while (1)
	{
		if (!strcmp(name, "0"))
			inquiry(head, read);
		else
		{
			judge = 1;              //判断图书是否存在
			for (p = head->next; p != NULL; p = p->next)
			{
				if (!strcmp(p->name_aurthor, name))
				{
					judge = 0;
					printf("图书编号：%d\n", p->no_book);
					printf("图书名字：");
					puts(p->name_book);
					printf("单价：%.2f\n", p->price);
					printf("作者姓名：");
					puts(p->name_aurthor);
					printf("借阅状态：%c\n", p->state);
					printf("读者编号：%d", p->no_reader);
					printf("\n");
					break;
				}
			}
			if (judge == 1)
			{
				printf("未找到图书，重新输入（0返回上一菜单）：");
				gets(name);
			}
			else
			{
				printf("输入需要查询的作者名称（0返回上一菜单）：");
				gets(name);
			}
		}
	}
}


//图书信息管理
void look_book(book *head, reader *read);          //图书浏览
void creatline_book(book *head, reader *read);     //新增图书
void modify_book(book *head, reader *read);        //修改图书
void delete_book(book *head, reader *read);        //删除图书

void manage_book(book *head, reader *read)
{

	system("cls");
	fflush(stdin);
	int choose;

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
	scanf("%d", &choose);
	getchar();
	while (1)
	{
		switch (choose)
		{
		case 0:show_menu(head, read);
			break;
		case 1: look_book(head, read);
			break;
		case 2:creatline_book(head, read);
			break;
		case 3:modify_book(head, read);
			break;
		case 4:delete_book(head, read);
			break;
		case 5://排序
			break;
		}
		if (choose < 0 || choose>5)
		{
			printf("输入错误，请输入0-5\n");
			scanf("%d", &choose);
			getchar();
		}
	}
}
void look_book(book *head, reader *read)
{
	system("cls");
	book *p;
	char ch;
	for (p = head->next; p != NULL; p = p->next)
	{
		printf("图书编号：%d\n", p->no_book);
		printf("图书名字：");
		puts(p->name_book);
		printf("单价：%.2f\n", p->price);
		printf("作者姓名：");
		puts(p->name_aurthor);
		printf("借阅状态：%c\n", p->state);
		printf("读者编号：%d", p->no_reader);
		printf("\n\n");

	}
	printf("任意键返回上一菜单");
	if (scanf("%c", &ch))
	{
		getchar();
		manage_book(head, read);
	}
}
void creatline_book(book *head, reader *read)
{

	system("cls");
	printf("			新增图书\n");
	printf("	-------------------------------------\n");
	book *p, *q;
	p = LEN;
	printf("输入图书编号：(0返回上一菜单）");
	scanf("%d", &p->no_book);
	getchar();
	while (p->no_book != 0)
	{
		int judge = 1;         //判断图书是否存在
		for (q = head->next; q != NULL; q = q->next)
		{
			if (p->no_book == q->no_book)
			{
				judge = 0;
				free(p);
			}
		}
		if (judge == 1)
		{
			printf("输入图书名字：");
			gets(p->name_book);
			printf("输入单价：");
			scanf("%f", &p->price);
			getchar();
			printf("输入作者姓名：");
			gets(p->name_aurthor);
			p->state = 'N';
			/*printf("输入读者编号：(若无输入0）");
			scanf("%d", &p->no_reader);
			getchar();*/
			p->no_reader = 0;
			printf("\n");
			p->next = head->next;
			head->next = p;
			p = LEN;
			fflush(stdin);
			system("cls");
			printf("			新增图书\n");
			printf("	-------------------------------------\n");
			printf("输入图书编号：（0返回上一菜单）");
			scanf("%d", &p->no_book);
			getchar();
		}
		else
		{
			printf("已有图书,输入图书编号：");
			p = LEN;
			scanf("%d", &p->no_book);
			getchar();
		}
	}
	free(p);
	manage_book(head, read);
}
void modify_book(book *head, reader *read)
{
	system("cls");
	printf("			修改图书\n");
	printf("	-------------------------------------\n");
	int num,judge;
	book *p,*q;

	printf("输入需要修改的图书编号（0返回上一菜单）：");
	scanf("%d", &num);
	getchar();
	while (1)
	{
		if (num == 0)
			manage_book(head, read);
		else
		{
			judge = 1;            //判断图书是否存在
			for (p = head->next; p != NULL; p = p->next)
			{
				if (p->no_book == num)
				{
					system("cls");
					printf("原图书编号：%d\n", p->no_book);
					printf("原图书名字：");
					puts(p->name_book);
					printf("原单价：%f\n", p->price);
					printf("原作者姓名：");
					puts(p->name_aurthor);
					printf("-------------------------\n");
					judge = 0;
					while (1)
					{
						int num2;
						printf("输入修改后图书编号：");
						scanf("%d", &num2);
						getchar();
						int judge2 = 1;           //判断图书编号是否已经存在
						for (q = head->next; q != NULL; q = q->next)
						{
							if (num2 == q->no_book)
							{
								judge2 = 0;
							}
						}
						if (judge2 == 1)
						{
							p->no_book = num2;
							break;
						}
						else
						{
							printf("已有图书,");
						}
					}
					printf("输入修改后图书名字：");
					gets(p->name_book);
					printf("输入修改后单价：");
					scanf("%f", &p->price);
					getchar();
					printf("输入修改后作者姓名：");
					gets(p->name_aurthor);
					/*printf("输入修改后读者编号：（若无输入0）");
					scanf("%d", &p->no_reader);
					getchar();*/
					printf("\n");
					break;

				}
			}
			if (judge == 1)
			{
				printf("未找到图书，重新输入（0返回上一菜单）：");
				scanf("%d", &num);
				getchar();
			}
			else
			{
				printf("输入需要修改的图书编号（0返回上一菜单）：");
				scanf("%d", &num);
				getchar();
			}
		}
	}
}
void delete_book(book *head, reader *read)
{
	system("cls");
	printf("			删除图书\n");
	printf("	-------------------------------------\n");
	int num, judge;
	book *p, *q,*r;
	char choose;

	printf("输入需要删除的图书编号（0返回上一菜单）：");
	scanf("%d", &num);
	getchar();
	while (1)
	{
		if (num == 0)
			manage_book(head, read);
		else
		{ 
			judge = 1;               //防止删除为第一个结点
			for (p = head->next; p != NULL; p = p->next)
			{
				if (p->next != NULL)
				{
					q = p->next;
					r = head->next;   //防止删除为第一个结点
				}
				else
				{
					q = p;
					r = head->next;//防止删除为第一个结点
				}
				if (q->no_book == num || r->no_book == num)
				{

					judge = 0;
					printf("请问您确认要删除吗？<Y\\N>");
					while (scanf("%c", &choose))
					{
						getchar();
						switch (choose)
						{
						case 'y':
						case 'Y':if (r->no_book == num)
									{
										p->next = r->next;
										head->next = r->next;
										free(r); 
									}
								 else
								 {
									 p->next = q->next;
										free(q);
								 }
								 printf("删除成功\n");
								 system("pause");
								 break;
						case 'n':
						case 'N':
							break;
						}
						if (choose != 'y' && choose != 'Y' && choose != 'N' && choose != 'n')
						{
							printf("输入错误，重新输入\n");
							printf("请问您确认要删除吗？<Y\\N>\n");
						}
						else
							break;
					}
					break;
				}
			}
		}
			if (judge == 1)
			{
				system("cls");
				printf("未找到图书，重新输入（0返回上一菜单）：");
				scanf("%d", &num);
				getchar();
			}
			else
			{
				system("cls");
				printf("输入需要删除的图书编号（0返回上一菜单）：");
				scanf("%d", &num);
				getchar();
			}
	}
 }


//读者信息管理
void creatarray_reader(book *head, reader *read);  //新增读者
void look_reader(book *head, reader *read);        //读者浏览
void modify_reader(book *head, reader *read);      //修改读者
void delete_reader(book *head, reader *read);      //删除读者

void manage_reader(book *head, reader *read)
{
	system("cls");
	int choose;
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
	getchar();
	while (1)
	{
		switch (choose)
		{
		case 0:show_menu(head, read);
			break;
		case 1: look_reader(head, read);
			break;
		case 2:creatarray_reader(head, read);
			break;
		case 3:modify_reader(head, read);
			break;
		case 4: delete_reader(head, read);
			break;
		case 5://排序
			break;
		}
		if (choose < 0 || choose>5)
		{
			printf("输入错误，请输入0-5\n");
			scanf("%d", &choose);
			getchar();
		}
	}
}
void creatarray_reader(book *head, reader *read)
{
	int j;
	static int i=0;
	for (i; i < N; i++)
	{
	   system("cls");
	   printf("			新增读者\n");
	   printf("	-------------------------------------\n");
	   printf("输入读者编号：（0返回上一菜单)");
	   scanf("%d", &read[i].no_reader2);
	   getchar();
	   for (j = 0; j < i; j++)
	   {
			if (read[i].no_reader2 == 0)
				manage_reader(head, read);
			else if (read[i].no_reader2 == read[j].no_reader2)
			{
				printf("已有读者，请重新输入(0返回上一菜单)");
				scanf("%d", &read[i].no_reader2);
				getchar();
				j = 0;
			}
		}
		printf("请输入读者姓名：");
		gets(read[i].name_reader);
		printf("请输入性别<男/女>：");
		gets(read[i].sex);
		printf("请输入年龄：");
		scanf("%d", &read[i].age);
		getchar();
		printf("请输入所在系：");
		gets(&read[i].pro);
		printf("\n");
		read[i].no_borrow = 0;
		readnum = i + 1;
	}
}
void look_reader(book *head, reader *read)
{
	system("cls");
	int j;
	for (j = 0; j < readnum; j++)
	{
		if (read[j].no_reader2 != 0)     //略过所有读者号为0的数据
		{
			printf("读者编号：%d\n", read[j].no_reader2);
			printf("读者姓名：");
			puts(read[j].name_reader);
			printf("性别：");
			puts(read[j].sex);
			printf("年龄：%d\n", read[j].age);
			printf("所在系：");
			puts(&read[j].pro);
			printf("借阅书目：%d", read[j].no_borrow);
			printf("\n\n");
		}
	}
	system("pause");
	manage_reader(head, read);
}
void modify_reader(book *head, reader *read)
{
	int i, num;
	system("cls");
	printf("			修改读者\n");
	printf("	-------------------------------------\n");
	while (1)
	{
		printf("输入读者编号：（0返回上一菜单)");
		scanf("%d", &num);
		getchar();
		if (num == 0)
			manage_reader(head, read);
		int judge = 1;
		for (i = 0; i < readnum; i++)
		{
			
			if (num == read[i].no_reader2)
			{
				judge = 0;
				system("cls");
				printf("读者编号：%d\n",read[i].no_reader2);
				printf("原读者姓名：");
				puts(read[i].name_reader);
				printf("原读者性别：");
				puts(read[i].sex);
				printf("原读者年龄：%d\n",read[i].age);
				printf("原读者所在系：");
				puts(read[i].pro);
				printf("	-------------------------------------\n");
				printf("请输入修改后读者姓名：");
				gets(read[i].name_reader);
				printf("请输入修改后性别<男/女>：");
				gets(read[i].sex);
				printf("请输入修改后年龄：");
				scanf("%d", &read[i].age);
				getchar();
				printf("请输入修改后所在系：");
				gets(&read[i].pro);
				printf("\n");
				break;
			}
		}
		if (judge == 1)
			printf("未找到读者，重新输入");
	}
}
void delete_reader(book *head, reader *read)
{
	int i,j, num;
	system("cls");
	printf("			删除读者\n");
	printf("	-------------------------------------\n");
	while (1)
	{
		printf("输入读者编号：（0返回上一菜单)");
		scanf("%d", &num);
		getchar();
		if (num == 0)
			manage_reader(head, read);
		int judge = 1;
		for (i = 0,j=0; i < readnum; i++)
		{
			if (num == read[i].no_reader2)
			{
				judge = 0;
			}
			else if (num != read[i].no_reader2)
			{
				*(read + j) = *(read + i);
					j++;
			}
		}
		if (judge == 1)
			printf("未找到读者，重新输入");
		else
		{
			*(read + j) = *(read + j+1);
			readnum -= 1;
		}

	}
}


//借书
void borrow(book *head, reader *read)
{
	book *p;
	int num;
	while (1)
	{
		system("cls"); 
		printf("		借阅图书\n");
		printf("----------------------------\n");
		printf("输入图书编号：(0返回上一菜单）");
		scanf("%d", &num);
		getchar();
		if (num == 0)
			show_menu(head, read);
		int judge = 1;         //判断图书是否存在
		for (p = head->next; p != NULL; p = p->next)
		{
			if (p->no_book == num)
			{
				judge = 0;
				if (p->state == 'Y')
					judge = 2;     
				break;
			}
		}
		if (judge == 1)
		{
			printf("未找到图书，请重新输入：\n");
			system("pause");
		}
		else if (judge == 2)
		{
			printf("图书已借出，请重新输入：\n");
			system("pause");
		}
		else
		{
			while (1)
			{
				printf("输入读者编号：(0返回上一菜单）");
				int judge2, num2,i;
				scanf("%d", &num2);
				getchar();
				for (i = 0; i <= readnum; i++)
				{
					judge2 = 1;             //判断读者是否存在
					if (num2 == 0)
						show_menu(head, read);
					else if (read[i].no_reader2 == num2)
					{
						judge2 = 0;
						p->state = 'Y';
						read[i].no_borrow += 1;
						printf("借阅已完成\n");
						p->no_reader = read[i].no_reader2;            //改变图书读者编号
						system("pause");
						break;
					}
					
				}
				if (judge2 == 1)
					printf("未找到读者，请重新输入：\n");
				else
					break;
			}
				
		}
	}
}


//还书
void back(book *head, reader *read)
{
	book *p;
	int i,num;

	while(1)
	{
		system("cls");
		printf("请输入图书编号：(0返回上一菜单）");
		scanf("%d", &num);
		getchar();
		if (num == 0)
			show_menu(head, read);
		int judge = 1;           //判断图书是否存在
		for (p = head->next; p != NULL; p = p->next)
		{
			if (p->no_book == num)
			{
				judge = 0;
				if (p->state == 'N')
					judge = 2;
				break;
			}
		}
		if (judge == 1)
		{
			printf("未找到图书，请重新输入：\n");
			system("pause");
		}
		else if (judge == 2)
		{
			printf("图书已借出，请重新输入：\n");
			system("pause");
		}
		else
		{
			while (1)
			{
				printf("输入读者编号：(0返回上一菜单）");
				int judge2, num2, i;
				scanf("%d", &num2);
				getchar();
				for (i = 0; i <= readnum; i++)
				{
					judge2 = 1;             //判断读者是否存在
					if (num2 == 0)
						show_menu(head, read);
					else if (read[i].no_reader2 == num2)
					{
						judge2 = 0;
						if (num2 == p->no_reader)
						{
							p->state = 'N';
							read[i].no_borrow -= 1;
							printf("还书已完成\n");
							p->no_reader = 0;//图书读者编号清0
							system("pause");
						}
						else
						{
							printf("图书编号与读者编号不匹配，请重新输入：");
							system("pause");
						}
						break;
					}

				}
				if (judge2 == 1)
					printf("未找到读者，请重新输入：\n");
				else
					break;
			}

		}
	}
}


//系统管理
void lead_in(book *head, reader *read);            //文件导入
void lead_out(book *head, reader *read);           //文件导出

void manage_system(book *head, reader *read)
{
	system("cls");
	int choose;
	printf("			系统管理\n");
	printf("	-------------------------------------\n");
	printf("		  1.导 出 到 文 件\n");
	printf("		  2.从 文 件 导 入\n");
	printf("		  0.返回上一级菜单\n");
	printf("	-------------------------------------\n");
	printf("\n");
	printf("	请选择您想使用的功能<0-2>:");
	scanf("%d", &choose);
	getchar();
	while (1)
	{
		switch (choose)
		{
		case 0:show_menu(head, read);
			break;
		case 1:lead_out(head, read);
			break;
		case 2:lead_in(head, read);
			break;
		}
		if (choose < 0 || choose>2)
		{
			printf("输入错误，请输入0-2\n");
			scanf("%d", &choose);
			getchar();
		}
	}
}
void lead_out(book *head, reader *read)
{
	FILE *fp;
	book *p;
	fp = fopen("tushu.dat", "wb");
	if (fp == NULL)
	printf("不能打开文件\n");
	else
	{
		for (p = head->next; p != NULL; p = p->next)
			fwrite(&p, sizeof(book), 1, fp);
	}
	fclose(fp); 
	printf("导出成功\n");
	system("pause");
	manage_system(head, read);
}
void lead_in(book *head, reader *read)
{
	FILE *fp;
	book *p;
	fp = fopen("tushu.dat", "rb");
	if (fp == NULL)
		printf("不能打开文件\n");
	else
	{
		while (!feof(fp))
			fread(p, sizeof(book), 1, fp);
	}
	fclose(fp);
	printf("导入成功\n");
	system("pause");
	manage_system(head, read);
}


void end(book *head, reader *read)
{
	FILE *fp;
	book *p;
	system("cls");
	char choose;
	printf("是否需要导出数据<Y\\N>\n");
	while (scanf("%c", &choose))
	{
		getchar();
		switch (choose)
		{
		case 'y':
		case 'Y':
			fp = fopen("tushu.dat", "w");
			if (fp == NULL)
				printf("不能打开文件\n");
			else
			{
				for (p = head->next; p != NULL; p = p->next)
				{
					fwrite(p, sizeof(book), 1, fp);
				}
			}
			fclose(fp);
			exit(0);
			break;
		case 'n':
		case 'N':exit(0);
			break;
		default:printf("输入错误，重新输入\n");
			printf("是否需要导出数据<Y\\N>\n");
			break;
		}
	}
}