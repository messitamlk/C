#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef int ElemType;//数据类型
typedef struct DuLNode{

	ElemType data;
	struct DuLNode *prior;
	struct DuLNode *next;
}DuLNode, *DuLinkList;//线性表的双向链表储存结构
DuLinkList CreatList(void);//建立双向链表，并输入值
void tarverse_list(DuLinkList);//遍历
void ListInsert_DuL(DuLinkList, int, ElemType);
int main()
{
	int i, j;
	DuLinkList pHead = NULL;
	pHead = CreatList();//创建一个非循环双向链表
	tarverse_list(pHead);
	return  0;

}
DuLinkList CreatList(void)

{
	int len;
	int i;
	int val;//用来临时存放用户输入值

  DuLinkList pHead = (DuLinkList)malloc(sizeof(DuLinkList));//头节点
pHead->next =pHead->prior = NULL;
if (pHead == NULL)
{
	printf("分配失败！\n");
	exit(-1);
}
printf("请输入要生成链表节点数：len =");
scanf("%d", &len);
for (i = 0; i<len; ++i)
{
	printf("请输入第%d个节点的值：", i + 1);
	scanf("%d", &val);
	DuLinkList pNew = (DuLinkList)malloc(sizeof(DuLinkList));
	if (pNew == NULL)
	{
		printf("分配失败！\n");
		exit(-1);
	}
	pNew->data= val;
	pNew->next = pHead->next;
	pHead->next = pNew;
	pNew->prior = pHead;
	pHead->prior = pNew;
	pHead->prior->prior = pNew;
	

}
return pHead;
}
void tarverse_list(DuLinkList pHead)
{
	
	
	DuLinkList p = pHead->next;
		while (p)
		{
			printf(" %d ", p->data);
			p = p->next;
		}
		printf("\n");

	
}