#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef int ElemType;
#define SIZE  10
#define	SIZECRISE 1
#define	OVERFLOW 0
#define	OK  1
typedef struct LNode
{
	ElemType *elem;
	int length;
	int listsize;

}SqList;
bool CreateLinklist(SqList &L);//�������Ա�
 bool InputLinklist(SqList &L,int i, ElemType e);//�������Ա���iλ�õ�eԪ��
 bool DeleteLinkList(SqList &L, int, ElemType);//ɾ�����Ա�
 void PutLinkList(SqList &L);//������Ա�
 int main()
 {
	 SqList L;
	 int n,i,VAL;
	 CreateLinklist(L);
	 printf("���ǽ�������һ��ʮ�����������Ա�\n");
	 printf("����Ҫ���뼸��ֵ��\n");
	 scanf("%d",&n);
	 for (i = 1; i <= n; i++)
	 {
		 printf("�������%d����ֵ", i);
		 scanf("%d",&VAL);

		 InputLinklist(L, i, VAL );
	 }

	 
	 PutLinkList(L);
	 return 0;
 }
 bool CreateLinklist(SqList &L)

 {
	 L.elem = (ElemType*)malloc(SIZE * sizeof(ElemType));

	 if (!L.elem)
	 {
		 return OVERFLOW;

	 }
	 L.length = 0;
	 
	 L.listsize = SIZE;
	 return OK;
 }
 bool InputLinklist(SqList &L, int i, ElemType e)
 {
	 if (i < 1 || i >= L.length + 1)return OVERFLOW;
	 if (L.length >= L.listsize)
	 {
		 ElemType* newbase = (ElemType*)realloc(L.elem, (SIZECRISE + SIZE)* sizeof(ElemType));
		 if (!newbase) return OVERFLOW;
		 L.elem = newbase;
		 L.listsize += SIZECRISE;
	 }
	 ElemType* q = &(L.elem[i - 1]);
	 for (ElemType* p = &(L.elem[L.length - 1]); p >= q; --p)*(p + 1) = *p;
	 *q = e;
	 ++L.length;
	 return OK;
	 
 }
 bool DeleteLinkList(SqList &L, int i, ElemType e)
 {
	 if (i < 1 || i >= L.length + 1)return OVERFLOW;
	 ElemType * p = &(L.elem[i - 1]);
	 e = *p;
	 ElemType * q = L.elem + L.length - 1;//�ȼ��� ElemType * q = &L.elem [ L.length - 1];
	 for (++p; p <= q; ++p)*(p - 1) = *p;
	 --L.length;
	 return OK;
 }
 void PutLinkList(SqList &L)
 {
	 for (int i = 0; i <= L.length; i++)
		 printf("%d ", L.elem[i]);
 }