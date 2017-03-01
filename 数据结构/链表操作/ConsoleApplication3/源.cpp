#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef int ElemType;//���ݽṹ
typedef struct Node
{
	ElemType date;//������
	struct Node *pNext;//ָ����
} NODE, *PNODE;//NODE�ȼ���struct Node, PNODE�ȼ���struct Node*
PNODE create_list(void);//������
void tarverse_list(PNODE );//�������
bool is_empty(PNODE );//�ж������Ƿ�Ϊ��
int lenth_list(PNODE );//������
bool insert_list(PNODE);//����
bool delete_list(PNODE);//ɾ��
void sort_list(PNODE );//��С��������
PNODE MergeList(PNODE,PNODE,PNODE);//�ϲ�����

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
	int val;//������ʱ����û�����ֵ

	PNODE pHead = (PNODE)malloc(sizeof(NODE));//ͷ�ڵ�
	pHead->pNext = NULL;
	pHead->date = 0;
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
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (pNew == NULL)
		{
			printf("����ʧ�ܣ�\n");
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
		printf("����Ϊ�գ�");
	else printf("����Ϊ�գ�");
	printf("�������� %d\n", lenth_list(pHead));
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
	printf("�������� %d\n",len);
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

	printf("������Ҫ����Ľڵ�λ�ú�ֵ��");
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
		printf("����ʧ�ܣ�");
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
	printf("������Ҫɾ���Ľڵ�λ�ã�");
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