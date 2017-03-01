// 第二次实验.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>
typedef  int ElemType;
typedef struct LDode{
	ElemType data;
	struct LDode* next;
} LNode, *Linklist;
Linklist CreateList( );
void traverse(Linklist);
bool Delete(Linklist);

int main()
{
	Linklist L;
	L=CreateList();
	traverse(L);
	Delete(L);
	traverse(L);
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
}
bool Delete(Linklist L)
{
	int k,i,j;
	Linklist p,q,r;
	p=L;
	printf("请输入删除第几个节点后几个数：\n");
	scanf("%d%",&i,&j);
	for(k=1;k<i;k++)
	{	if(p->next)return false;
		p=p->next;
	free(r);
	p->next =q;
	}
	return true;

}

