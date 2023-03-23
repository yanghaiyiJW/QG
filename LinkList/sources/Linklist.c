#include "Linklist.h"
#include <stdlib.h>

//�������ܵ�
void menu()
{
	printf("******************************\n");
	printf("*        1.��ʼ������        *\n");
	printf("*        2.�����½ڵ�        *\n");
	printf("*        3.��ת����          *\n");
	printf("*        4.�������          *\n");
	printf("*        5.�м�����          *\n");
	printf("*        6.�ж��Ƿ�ɻ�      *\n");
	printf("*        7.ɾ���ڵ�          *\n");
	printf("*        8.��ż��ת          *\n");
	printf("*        9.��ѯ����          *\n");
	printf("*        10.����ѭ������     *\n");
	printf("*        11.�˳�ϵͳ         *\n");
	printf("******************************\n");
	

}


//��������
Status InitList(LinkedList L)
{
	printf("���������ڵ㣨������20����");
	int i,j;
	scanf("%d", &i);
	LinkedList p,q;
	q = L;
	for (j = 1; j <=i; j++) {
		
		p= (LinkedList)malloc(sizeof(LNode));
		if (p != NULL) {
			printf("�������%d���ڵ�����ݣ����Ȳ�����10����", j);
			scanf("%d", &p->data);
			p->next = q ->next;
			q->next = p;
			q = p;
		}
		p->next = NULL;
	}
	
	return SUCCESS;
}
//��������
void DestroyList(LinkedList L)
{
	L = (LinkedList)malloc(sizeof(LNode));
	LinkedList p;
	while (L)
	{
		p = L;
		L = L->next;
		free(p);
	}
}
//��������
Status InsertList(LNode* p, LNode* q)
{
	
	int i,j,k;
	printf("������Ҫ����λ�õ�ǰ������ݣ�");
	scanf("%d", &k);
	printf("������������ݵ�λ�ã��ڼ�����");
	scanf("%d", &i);
	printf("������Ҫ��������ݣ�");
	scanf("%d", &q->data);
	for (j = 0; j< i; j++) {
		p = p->next;
	}
	q->next = p->next;
	p->next = q;
	
	return SUCCESS;
}
//ɾ������
Status DeleteList(LNode* p, ElemType* e)
{
	
	int i,j;
	LNode* q;
	printf("���������ݵ�λ�ã�");
	scanf("%d", &i);
	for(j=1;j<i;j++)
	{
		p = p->next;
	};
	
	q = p->next;
	p ->next= q->next;
	free(q);
	return SUCCESS;
}
//�������
void PrintList(LinkedList L)
{
	LNode* p;
	p = L->next;
	while (p != NULL) {
		printf("%d->", p->data);
		p = p->next;

	};
	printf("NULL");
}
//��������
Status SearchList(LinkedList L, ElemType e)
{
	printf("������Ҫ���ҵ����ݣ�");
	scanf("%d",&e);
	LNode* p;
	p = L->next;
	if (e != p->data) {
		p = p->next;
		if (e == p->data) {
			printf("���ڴ����ݣ�");
		}
		else
			printf("�����ڴ����ݣ�");
	}
	
	return SUCCESS;
}
//�����м�����
LNode * FindMidNode(LinkedList  L)
{
	int i=0,j;
	LinkedList p,q;
	p = L->next;
	
	while (p != NULL)
	{
		p = p->next;
		++i;
	}
	q = L->next;
	for (j = 1; j < i / 2+1; j++)
	{
		q = q->next;
	}
	return q;
}

//ԭ�ط�ת
Status ReverseList(LinkedList  L)
{
	LinkedList p, q;
	p = L->next;
	q = L->next->next;
	while (q != NULL)
	{
		p->next = q->next;
		q->next = L->next;
		L->next = q;
		q = p ->next;
	}
	return SUCCESS;
}
//��ż��ת
LNode* ReverseEvenList(LinkedList L)
{
	LinkedList q, p;
	p = L->next;
	q = L->next->next;
	ElemType e;
	while (p->next!=NULL)
	{
		
		if (((p->data) % 2 == 0&&(q->data)%2!=0)||((p->data)%2!=0&&(q->data)%2==0))
		{
			e = p->data;
			p->data = q->data;
			q->data = e;
			p = p->next;
			q = q->next;
		}
		else
		{
			p = p->next;
			q = q->next;
		}
		
		
	}
	printf("��ת�ɹ���");
	return L;
}
//�ж��Ƿ�ɻ�
Status IsLoopList(LinkedList L)
{
	

	LinkedList p, q;
	q = L->next;
	p = L->next;
	while (p && p->next)
	{
		p = p->next->next;
		q = q->next;
		if (p == q)
		{
			printf("�����ѳɻ���");
			return SUCCESS;
			break;
		}
		
	}
	return ERROR;
}
//�������ѭ������
Status InitLoopList(LinkedList L)
{
	LinkedList p;
	p = L->next;
	while (p->next != NULL) 
	{
		p = p->next;
	}
	p->next = L->next;
	return SUCCESS;
}