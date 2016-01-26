/* main6-5.c ����bo6-5.c�������� */
#include "../ch1/c1.h"
typedef char TElemType;
TElemType Nil = ' '; /* �Կո��Ϊ�� */
#include "c6-5.h"
#include "bo6-5.c"

void vi(TElemType c)
{
	printf("%c ", c);
}

void main()
{
	int i;
	CSTree T, p, q;
	TElemType e, e1;
	InitTree(&T);
	printf("���������,���շ�? %d(1:�� 0:��) ����Ϊ%c �������Ϊ%d\n", TreeEmpty(T), Root(T), TreeDepth(T));
	CreateTree(&T);
	printf("������T��,���շ�? %d(1:�� 0:��) ����Ϊ%c �������Ϊ%d\n", TreeEmpty(T), Root(T), TreeDepth(T));
	printf("�ȸ�������T:\n");
	PreOrderTraverse(T, vi);
	printf("\n��������޸ĵĽ���ֵ ��ֵ: ");
	scanf("%c%*c%c%*c", &e, &e1);
	Assign(&T, e, e1);
	printf("��������޸ĺ����T:\n");
	PostOrderTraverse(T, vi);
	printf("\n%c��˫����%c,������%c,��һ���ֵ���%c\n", e1, Parent(T, e1), LeftChild(T, e1), RightSibling(T, e1));
	printf("������p:\n");
	InitTree(&p);
	CreateTree(&p);
	printf("���������p:\n");
	LevelOrderTraverse(p, vi);
	printf("\n����p�嵽��T�У�������T��p��˫�׽�� �������: ");
	scanf("%c%d%*c", &e, &i);
	q = Point(T, e);
	InsertChild(&T, q, i, p);
	printf("���������T:\n");
	LevelOrderTraverse(T, vi);
	printf("\nɾ����T�н��e�ĵ�i��������������e i: ");
	scanf("%c%d", &e, &i);
	q = Point(T, e);
	DeleteChild(&T, q, i);
	printf("���������T:\n", e, i);
	LevelOrderTraverse(T, vi);
	printf("\n");
	DestroyTree(&T);
}