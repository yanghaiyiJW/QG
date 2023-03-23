#include <stdio.h>
#include <stdlib.h>
#include "Linklist.h"
#include <windows.h>
int main()
{
	menu();
	int n;
	LinkedList L;
	L = (LinkedList)malloc(sizeof(LNode));
	L->next = NULL;

	printf("请输入对应的数字：");
	scanf("%d", &n);
	if (n == 11)
	{
		printf("退出系统");
	}
	else
	{
		if (n == 1)
		{
			InitList(L);
			printf("初始化成功！");
			printf("\n");
			while (1)
			{
				system("pause");
				system("cls");
				menu();
				printf("\n");
				
				if (IsLoopList(L) == ERROR)
				{
					printf("请输入对应的数字：");
					scanf("%d", &n);
					if (n == 11)
					{
						printf("退出系统");
						break;//跳出循环
					}
					switch (n)
					{
					case 2:
					{
						LinkedList q;
						q = (LinkedList)malloc(sizeof(LNode));
						InsertList(L, q);
						PrintList(L);
						break;
					}

					case 3:
						ReverseList(L);
						printf("反转成功！");
						break;
					case 4:
						PrintList(L);
						break;
					case 5:
						printf("中间链表的数据为%d", FindMidNode(L)->data);
						break;
					case 6:
						IsLoopList(L);
						if (IsLoopList(L) == ERROR)
						{
							printf("链表未成环！");
						}
						break;

					case 7:
					{
						ElemType e = 0;
						printf("请输入要删除的数据：\n");
						scanf_s("%d", &e);
						DeleteList(L, &e);
						PrintList(L);
						break;
					}
					case 8:
						ReverseEvenList(L);
						break;
					case 9:
					{
						ElemType e = 0;
						SearchList(L, e);
						break;
					}
					case 10:
						InitLoopList(L);
						printf("链表成环完成");
						break;
					}
					printf("\n");
				}
				else
				{
					printf("链表已成环！");
					break;
				}
				
			}

		}
		else
			printf("未初始化！");
		


			
		
	}




			return 0;

}