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

	printf("�������Ӧ�����֣�");
	scanf("%d", &n);
	if (n == 11)
	{
		printf("�˳�ϵͳ");
	}
	else
	{
		if (n == 1)
		{
			InitList(L);
			printf("��ʼ���ɹ���");
			printf("\n");
			while (1)
			{
				system("pause");
				system("cls");
				menu();
				printf("\n");
				
				if (IsLoopList(L) == ERROR)
				{
					printf("�������Ӧ�����֣�");
					scanf("%d", &n);
					if (n == 11)
					{
						printf("�˳�ϵͳ");
						break;//����ѭ��
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
						printf("��ת�ɹ���");
						break;
					case 4:
						PrintList(L);
						break;
					case 5:
						printf("�м����������Ϊ%d", FindMidNode(L)->data);
						break;
					case 6:
						IsLoopList(L);
						if (IsLoopList(L) == ERROR)
						{
							printf("����δ�ɻ���");
						}
						break;

					case 7:
					{
						ElemType e = 0;
						printf("������Ҫɾ�������ݣ�\n");
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
						printf("����ɻ����");
						break;
					}
					printf("\n");
				}
				else
				{
					printf("�����ѳɻ���");
					break;
				}
				
			}

		}
		else
			printf("δ��ʼ����");
		


			
		
	}




			return 0;

}