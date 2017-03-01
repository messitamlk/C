


#include<stdio.h>
#include<malloc.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT   10
#define ERROR   -1
typedef struct Date{
	int date;
	
}PNODE;
typedef struct {
	
	struct Date* elem;
	int length;
	int listsize;
}SqList;
int InitList(SqList&L);
int ListInset_Sq(SqList&L,int i,PNODE e);
int ListPrint(SqList&L);
int ListScanf(SqList&l,int e,int site);
int main(void)
{	
  PNODE n,i,val,pos;
	SqList  l;
    InitList(l);
	printf("请问要输入几个值\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("请请输入第%d的值\n",i);
		scanf("%d",&val);
		printf("放在什么位置：\n",i);
		scanf("%d",&pos);
		ListScanf(l,val,pos);
	}	
	ListPrint(l);
	return 0;
}
int InitList(SqList&l)
{
	l.elem =(struct Date *)malloc(LIST_INIT_SIZE *sizeof(PNODE));
	if(!l.elem)return ERROR;
	l.length = 0;
	l.listsize = LIST_INIT_SIZE;
	return 0;
}
int ListInset_Sq(SqList&l,int i,PNODE e)
{
	struct Date* p;
    struct Date* newbase;
	struct Date* q;
	
	if(i<1||i>(l.length+1)) return ERROR;
	if(l.length>=l.listsize)
	{	
		newbase = (struct Date *)realloc(l.elem,(l.listsize+ LISTINCREMENT)*sizeof(struct Date));
		if(!newbase)return ERROR;
		l.listsize+=LISTINCREMENT;
		l.elem = newbase;
	}

	q= &(l.elem[i-1]);
	for(p = &(l.elem[l.length-1]);p>=q;--p)
		*(p+1) = *p;
	*q =e;
	++l.length;
	return 0;
}
int ListPrint(SqList&l)
{
	int i;
	
	if(!l.elem)return ERROR;
	for(i =0;i<=l.length;i++)
	
	{printf("%d ",l.elem[i].date);}

}
int ListScanf(SqList&l,int e,PNODE site)
{
		struct Date* q;
		struct Date* newbase;
		if(l.length>=l.listsize)
	{	
		newbase = (struct Date *)realloc(l.elem,(l.listsize+ LISTINCREMENT)*sizeof(struct Date));
		if(!newbase)return ERROR;
		l.listsize+=LISTINCREMENT;
	
	}
		if(site>=l.length)return ERROR;
		q=&l.elem[site];
		*q =e;
		return 0;

}