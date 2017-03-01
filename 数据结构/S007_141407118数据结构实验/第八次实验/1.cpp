// 第二次实验.cpp : Defines the entry point for the console application.
//

#include<stdio.h>
#include<malloc.h>
typedef  int ElemType;
typedef struct LDode{
	ElemType data;
	struct LDode* next;
} LNode, *Linklist;
Linklist CreateList( );
void traverse(Linklist);
void sort(Linklist);

int main()
{
	Linklist La;
	La=CreateList();
	traverse(La);
	sort(La);
	traverse(La);
	
	return 0;
}

Linklist CreateList()
{
	Linklist L,pNew;
	int i,n; 
	printf("请问要建立几个节点？\n");
	scanf("%d",&n);
	L=(Linklist)malloc(sizeof(LNode));//头结点
	L->next = NULL;
	L->data = n;
	for(i=1;i<=n;i++)
	{
		pNew = 	(Linklist)malloc(sizeof(LNode));
		printf("请输入第%d的值：",i);
		scanf("%d",&pNew->data);
		pNew->next = L->next;
		L->next = pNew;
	
	}
return L;
}
void traverse(Linklist L)
{
	Linklist p;
	p = L->next;
	while(p)
	{
		
		printf("%d  ",p->data);
		p =p->next;
	}
		printf("\n");
}
void sort(Linklist L){
Linklist p,q;
int n,i,r;
n=L->data;
for(i=2;i<=n;++i)
for(p=L->next,q=p->next;p->next;p=p->next,q=q->next)
{
	if(p->data>q->data){r=p->data;p->data=q->data;q->data=r;}
}
	
}