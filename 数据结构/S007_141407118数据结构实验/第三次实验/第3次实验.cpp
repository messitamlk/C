// �ڶ���ʵ��.cpp : Defines the entry point for the console application.
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

int main()
{
	Linklist La,Lb;
	La=CreateList();
	traverse(La);
	Lb=CreateList();
	traverse(Lb);
	
	return 0;
}

Linklist CreateList()
{
	Linklist L,pNew;
	int i,n; 
	printf("����Ҫ���������ڵ㣿\n");
	scanf("%d",&n);
	L=(Linklist)malloc(sizeof(LNode));//ͷ���
	L->next = NULL;
	L->data = n;
	for(i=1;i<=n;i++)
	{
		pNew = 	(Linklist)malloc(sizeof(LNode));
		printf("�������%d��ֵ��",i);
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
