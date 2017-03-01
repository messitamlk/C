#include<stdio.h>
#include<malloc.h>
typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;


}LNode ,*LinkList;
LinkList CreateLinklist();
void tarverse_list(LinkList phead);
int main()
{
	LinkList La, Lb;
	La = CreateLinklist();
	tarverse_list(La);
	return 0;
}
LinkList CreateLinklist()
{
	int n,i;   LinkList pHead,pNew;
	printf("请问需要几个节点？\n");
	scanf("%d", &n);
	pHead = (LinkList)malloc(sizeof(LNode));//头结点
	pHead->next = NULL; pHead->data = n;
	for (i = 1; i <= n; i++)
	{
		printf("请输入第%d个节点的值：",i);
		pNew = (LinkList)malloc(sizeof(LNode));
		scanf("%d", &pNew->data);
		pNew->next = pHead->next;
		pHead->next = pNew;
	}
	return pHead;

}
void tarverse_list(LinkList phead)
{
	LinkList p = phead->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");

}