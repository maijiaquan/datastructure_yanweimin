/* algo2-4.c �޸��㷨2.7�ĵ�һ��ѭ������е��������Ϊ������䣬�ҵ� */
/* *pa=*pbʱ��ֻ��������֮һ����Lc���˲����Ľ�����㷨2.1��ͬ */
#include "../ch1/c1.h"
typedef int ElemType;
#include "c2-1.h"
#include "bo2-1.c"

int comp(ElemType c1, ElemType c2)
{
	int i;
	if (c1 < c2)
		i = 1;
	else if (c1 == c2)
		i = 0;
	else
		i = -1;
	return i;
}

void MergeList(SqList La, SqList Lb, SqList *Lc)
{ /* ��һ�ֺϲ����Ա��ķ����������㷨2.7�µ�Ҫ���޸��㷨2.7�� */
	ElemType  *pa, *pa_last, *pb, *pb_last, *pc;
	pa = La.elem;
	pb = Lb.elem;
	(*Lc).listsize = La.length + Lb.length; /* �˾����㷨2.7��ͬ */
	pc = (*Lc).elem = (ElemType *)malloc((*Lc).listsize*sizeof(ElemType));
	if (!(*Lc).elem)
		exit(OVERFLOW);
	pa_last = La.elem + La.length - 1;
	pb_last = Lb.elem + Lb.length - 1;
	while (pa <= pa_last&&pb <= pb_last) /* ��La�ͱ�Lb���ǿ� */
		switch (comp(*pa, *pb)) /* �˾����㷨2.7��ͬ */
		{
		case  0: pb++;
		case  1: *pc++ = *pa++;
			break;
		case -1: *pc++ = *pb++;
		}
	while (pa <= pa_last) /* ��La�ǿ��ұ�Lb�� */
		*pc++ = *pa++;
	while (pb <= pb_last) /* ��Lb�ǿ��ұ�La�� */
		*pc++ = *pb++;
	(*Lc).length = pc - (*Lc).elem; /* �Ӵ˾� */
}

void print(ElemType *c)
{
	printf("%d ", *c);
}

void main()
{
	SqList La, Lb, Lc;
	int j;
	InitList(&La); /* �����ձ�La */
	for (j = 1; j <= 5; j++) /* �ڱ�La�в���5��Ԫ�� */
		ListInsert(&La, j, j);
	printf("La= "); /* �����La������ */
	ListTraverse(La, print);
	InitList(&Lb); /* �����ձ�Lb */
	for (j = 1; j <= 5; j++) /* �ڱ�Lb�в���5��Ԫ�� */
		ListInsert(&Lb, j, 2 * j);
	printf("Lb= "); /* �����Lb������ */
	ListTraverse(Lb, print);
	MergeList(La, Lb, &Lc);
	printf("Lc= "); /* �����Lc������ */
	ListTraverse(Lc, print);
}