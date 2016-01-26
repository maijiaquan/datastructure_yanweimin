/* algo10-2.c ��̬���� */
#include "../ch1/c1.h"
typedef int InfoType; /* ������������������� */
#include "c10-2.h"
void TableInsert(SLinkListType *SL, RedType D[], int n)
{ /* ������D����n��Ԫ�صı���������ľ�̬����SL */
	int i, p, q;
	(*SL).r[0].rc.key = INT_MAX; /* ��ͷ����¼�Ĺؼ���ȡ�������(�ǽ��������ı�β) */
	(*SL).r[0].next = 0; /* next��Ϊ0��ʾ��β(��Ϊ�ձ�����ʼ��) */
	for (i = 0; i < n; i++)
	{
		(*SL).r[i + 1].rc = D[i]; /* ������D��ֵ������̬����SL */
		q = 0;
		p = (*SL).r[0].next;
		while ((*SL).r[p].rc.key <= (*SL).r[i + 1].rc.key)
		{ /* ��̬��������� */
			q = p;
			p = (*SL).r[p].next;
		}
		(*SL).r[i + 1].next = p; /* ����ǰ��¼���뾲̬���� */
		(*SL).r[q].next = i + 1;
	}
	(*SL).length = n;
}

void Arrange(SLinkListType *SL)
{ /* ���ݾ�̬����SL�и�����ָ��ֵ������¼λ�ã�ʹ��SL�м�¼���ؼ��� */
  /* �ǵݼ�����˳������ �㷨10.3 */
	int i, p, q;
	SLNode t;
	p = (*SL).r[0].next; /* pָʾ��һ����¼�ĵ�ǰλ�� */
	for (i = 1; i < (*SL).length; ++i)
	{ /* (*SL).r[1..i-1]�м�¼�Ѱ��ؼ�����������,��i����¼��SL�еĵ�ǰλ��Ӧ��С��i */
		while (p < i)
			p = (*SL).r[p].next; /* �ҵ���i����¼������pָʾ����SL�е�ǰλ�� */
		q = (*SL).r[p].next; /* qָʾ��δ�����ı�β */
		if (p != i)
		{
			t = (*SL).r[p]; /* ������¼��ʹ��i����¼��λ */
			(*SL).r[p] = (*SL).r[i];
			(*SL).r[i] = t;
			(*SL).r[i].next = p; /* ָ�����ߵļ�¼��ʹ���Ժ����whileѭ���һ� */
		}
		p = q; /* pָʾ��δ�����ı�β��Ϊ�ҵ�i+1����¼��׼�� */
	}
}

void Sort(SLinkListType L, int adr[])
{ /* ���adr[1..L.length]��adr[i]Ϊ��̬����L�ĵ�i����С��¼����� */
	int i = 1, p = L.r[0].next;
	while (p)
	{
		adr[i++] = p;
		p = L.r[p].next;
	}
}

void Rearrange(SLinkListType *L, int adr[])
{ /* adr������̬����L��������򣬼�L.r[adr[i]]�ǵ�iС�ļ�¼�� */
  /* ���㷨��adr����L.r��ʹ�������㷨10.18(L�������б�) */
	int i, j, k;
	for (i = 1; i < (*L).length; ++i)
		if (adr[i] != i)
		{
			j = i;
			(*L).r[0] = (*L).r[i]; /* �ݴ��¼(*L).r[i] */
			while (adr[j] != i)
			{ /* ����(*L).r[adr[j]]�ļ�¼��λֱ��adr[j]=iΪֹ */
				k = adr[j];
				(*L).r[j] = (*L).r[k];
				adr[j] = j;
				j = k; /* ��¼����λ */
			}
			(*L).r[j] = (*L).r[0];
			adr[j] = j;
		}
}

void print(SLinkListType L)
{
	int i;
	for (i = 1; i <= L.length; i++)
		printf("key=%d ord=%d next=%d\n", L.r[i].rc.key, L.r[i].rc.otherinfo, L.r[i].next);
}

#define N 8
void main()
{
	RedType d[N] = { {49,1},{38,2},{65,3},{97,4},{76,5},{13,6},{27,7},{49,8} };
	SLinkListType l1, l2;
	int *adr, i;
	TableInsert(&l1, d, N);
	l2 = l1; /* ���ƾ�̬����l2��l1��ͬ */
	printf("����ǰ:\n");
	print(l1);
	Arrange(&l1);
	printf("l1�����:\n");
	print(l1);
	adr = (int*)malloc((l2.length + 1)*sizeof(int));
	Sort(l2, adr);
	for (i = 1; i <= l2.length; i++)
		printf("adr[%d]=%d ", i, adr[i]);
	printf("\n");
	Rearrange(&l2, adr);
	printf("l2�����:\n");
	print(l2);
}