#include<stdio.h>
#include<malloc.h>
typedef  int ElemType;
typedef struct LDode{
	ElemType data;
	struct LDode* next;
} LNode, *Linklist;
Linklist CreateList( );
void traverse(Linklist);
 Linklist  bing(Linklist La,Linklist Lb);

int main()
{
	Linklist La,Lb;
	La=CreateList();
	traverse(La);
	Lb=CreateList();
	traverse(Lb);
	
	traverse(bing(La,Lb));
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
 Linklist  bing(Linklist La,Linklist Lb)
 {
	Linklist pa ,pb,pc,p;
	int k =0,i;
	pa = La->next;
	pb =Lb->next;
	p = Lb->next;
	while(p)
	{
		
		k++;
		p =p->next;
	}
	for(i = 0;i<=k;i++)
	{
		while(pa)
	{
		if(pa->data==pb->data)//相等则删除pb
		{
			pc = pb;			
			pb = pb->next;
			Lb->next =pb; 
			pc->next = NULL;
			free(pc);
			
		}
		pa = pa->next;
	}
	Lb->next = pb->next;
	pb->next = pa->next;
	pa->next = pb;
	pb =Lb->next;
	
	}
	return La;
 }