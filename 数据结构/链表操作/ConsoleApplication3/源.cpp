#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef int ElemType;//数据结构
typedef struct Node
{
	ElemType date;//数据域；
	struct Node *pNext;//指针域
} NODE, *PNODE;//NODE等价于struct Node, PNODE等价于struct Node*
PNODE create_list(void);//链表建立
void tarverse_list(PNODE );//输出链表
bool is_empty(PNODE );//判断链表是否为空
int lenth_list(PNODE );//链表长度
bool insert_list(PNODE);//插入
bool delete_list(PNODE);//删除
void sort_list(PNODE );//从小到大排序
PNODE MergeList(PNODE,PNODE,PNODE);//合并链表

int main(void)
{
	PNODE La, Lb,Lc;
	La = create_list();
	Lb = create_list();
	MergeList(La, Lb,Lc);
	tarverse_list(La);
	
	return 0;
}
PNODE create_list(void)
{
	int len;
	int i;
	int val;//用来临时存放用户输入值

	PNODE pHead = (PNODE)malloc(sizeof(NODE));//头节点
	pHead->pNext = NULL;
	pHead->date = 0;
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
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (pNew == NULL)
		{
			printf("分配失败！\n");
			exit(-1);
		}
		pNew->date = val;
		pNew->pNext = pHead->pNext;
		pHead->pNext = pNew;

	}
	return pHead;
}
void tarverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	 if (is_empty(pHead))
		printf("链表为空！");
	else printf("链表不为空！");
	printf("链表长度是 %d\n", lenth_list(pHead));
	while (p)
	{
		printf(" %d ", p->date);
		p = p->pNext;
	}
	printf("\n");

}
bool is_empty(PNODE pHead)
{
	if (NULL == pHead->pNext)
		return true;
	else
		return false; 
}
int lenth_list(PNODE pHead)
{	int len = 0;
	PNODE p = pHead->pNext;
	while (p)
	{
		len++;
		p = p->pNext;
	}
	printf("链表长度是 %d\n",len);
	return len;
}
void sort_list(PNODE pHead)
{	
	PNODE q,r,s;
	int t;
	for (s = pHead->pNext; s->pNext != NULL; s =s->pNext)
		for (q = pHead; q ->pNext != NULL; q = q->pNext)
		{
			r = q->pNext;
			if (r->date <q->date)
			{ 
				t = q->date;
				q->date = r->date;
				r->date = t;

			}
		}
}
bool insert_list(PNODE pHead)
{
	int i=0,val,pos;
	PNODE p;
	p = pHead;

	printf("请输入要插入的节点位置和值：");
	scanf("%d %d", &pos, &val);
	while (p->pNext != NULL&&i < pos - 1)
	{
		p = p->pNext;
		i++;
	}
	if (i > pos - 1 || p->pNext == NULL)
		return false;
	PNODE pnew = (PNODE)malloc(sizeof(NODE));
	if (pnew == NULL)
	{
		printf("分配失败！");
		exit(-1);
	}
	pnew->date = val;
	pnew->pNext = p->pNext;
	p->pNext = pnew;
	return true;
}
bool delete_list(PNODE pHead )
{
	int i = 0, pos;
	printf("请输入要删除的节点位置：");
	scanf("%d %d", &pos);
	PNODE p,r;
	p = pHead;
	while (p->pNext != NULL&&i < pos - 1)
	{
		p = p->pNext;
		i++;
	}
	if (i > pos - 1 || p->pNext == NULL)
		return false;
	r = p->pNext;
	p->pNext = r->pNext;
	free(r);
	r = NULL;
	return true;


}
PNODE MergeList(PNODE La,PNODE Lb,PNODE Lc)
{
	PNODE pa, pb,pc;
	pa = La->pNext;
	pb = Lb->pNext;
	Lc = pc = La;
	while (pa&&pb)
	{
		if (pa->date <= pb->date)
		{pc->pNext = pa; pc = pa; pa = pa->pNext;}
		else { pc->pNext = pb; pc = pb; pb = pb->pNext; }
	}
	pc->pNext = pa ? pa : pb;
	free(Lb);
	return La;
}