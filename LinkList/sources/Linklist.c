#include "Linklist.h"
#include <stdlib.h>

//创建功能单
void menu()
{
	printf("******************************\n");
	printf("*        1.初始化链表        *\n");
	printf("*        2.插入新节点        *\n");
	printf("*        3.反转链表          *\n");
	printf("*        4.输出链表          *\n");
	printf("*        5.中间链表          *\n");
	printf("*        6.判断是否成环      *\n");
	printf("*        7.删除节点          *\n");
	printf("*        8.奇偶反转          *\n");
	printf("*        9.查询链表          *\n");
	printf("*        10.构造循环链表     *\n");
	printf("*        11.退出系统         *\n");
	printf("******************************\n");
	

}


//创建链表
Status InitList(LinkedList L)
{
	printf("创建几个节点（不超过20）：");
	int i,j;
	scanf("%d", &i);
	LinkedList p,q;
	q = L;
	for (j = 1; j <=i; j++) {
		
		p= (LinkedList)malloc(sizeof(LNode));
		if (p != NULL) {
			printf("请输入第%d个节点的数据（长度不超过10）：", j);
			scanf("%d", &p->data);
			p->next = q ->next;
			q->next = p;
			q = p;
		}
		p->next = NULL;
	}
	
	return SUCCESS;
}
//销毁数据
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
//插入数据
Status InsertList(LNode* p, LNode* q)
{
	
	int i,j,k;
	printf("请输入要插入位置的前面的数据：");
	scanf("%d", &k);
	printf("请输入这个数据的位置（第几个）");
	scanf("%d", &i);
	printf("请输入要插入的数据：");
	scanf("%d", &q->data);
	for (j = 0; j< i; j++) {
		p = p->next;
	}
	q->next = p->next;
	p->next = q;
	
	return SUCCESS;
}
//删除数据
Status DeleteList(LNode* p, ElemType* e)
{
	
	int i,j;
	LNode* q;
	printf("请输入数据的位置：");
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
//输出链表
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
//查找数据
Status SearchList(LinkedList L, ElemType e)
{
	printf("请输入要查找的数据：");
	scanf("%d",&e);
	LNode* p;
	p = L->next;
	if (e != p->data) {
		p = p->next;
		if (e == p->data) {
			printf("存在此数据！");
		}
		else
			printf("不存在此数据！");
	}
	
	return SUCCESS;
}
//查找中间数据
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

//原地反转
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
//奇偶反转
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
	printf("反转成功！");
	return L;
}
//判断是否成环
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
			printf("链表已成环！");
			return SUCCESS;
			break;
		}
		
	}
	return ERROR;
}
//单链表变循环链表
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