#pragma once
#include <stdio.h>


typedef int ElemType;

// define struct of linked list
typedef struct LNode {
	ElemType data;
	struct LNode* next;
} LNode, * LinkedList;

// define Status
typedef enum Status {
	ERROR,
	SUCCESS
} Status;

Status  InitList(LinkedList L);
void DestroyList(LinkedList L);
Status InsertList(LNode* p, LNode* q);
Status SearchList(LinkedList L, ElemType e);
Status DeleteList(LNode* p, ElemType* e);
void PrintList(LinkedList L);
LNode* FindMidNode(LinkedList  L);
Status ReverseList(LinkedList L);
LNode* ReverseEvenList(LinkedList L);
Status IsLoopList(LinkedList L);
Status InitLoopList(LinkedList L);
void menu();