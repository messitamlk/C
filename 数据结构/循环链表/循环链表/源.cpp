#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef int ElemType;//��������
typedef struct DuLNode{

	ElemType data;
	struct DuLNode *prior;
	struct DuLNode *next;
}DuLNode, *DuLinkList;//���Ա��˫��������ṹ
DuLinkList CreatList(void);//����˫������������ֵ
void tarverse_list(DuLinkList);//����
void ListInsert_DuL(DuLinkList, int, ElemType);
int main()
{
	int i, j;
	DuLinkList pHead = NULL;
	pHead = CreatList();//����һ����ѭ��˫������
	tarverse_list(pHead);
	return  0;

}
DuLinkList CreatList(void)

{
	int len;
	int i;
	int val;//������ʱ����û�����ֵ

  DuLinkList pHead = (DuLinkList)malloc(sizeof(DuLinkList));//ͷ�ڵ�
pHead->next =pHead->prior = NULL;
if (pHead == NULL)
{
	printf("����ʧ�ܣ�\n");
	exit(-1);
}
printf("������Ҫ��������ڵ�����len =");
scanf("%d", &len);
for (i = 0; i<len; ++i)
{
	printf("�������%d���ڵ��ֵ��", i + 1);
	scanf("%d", &val);
	DuLinkList pNew = (DuLinkList)malloc(sizeof(DuLinkList));
	if (pNew == NULL)
	{
		printf("����ʧ�ܣ�\n");
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