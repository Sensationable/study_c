# define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("**************************\n");
	printf("*****1.play    0.exit*****\n");
	printf("**************************\n");
}
void game()
{
	char ret = '0';
	char board[ROW][COL] = { 0 };
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	//����
	while (1)
	{
		//������壬���Ҵ�ӡ����
		PlayerMove(board, ROW, COL);
		//�ж���Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
		//�������壬���Ҵ�ӡ����
		ComputerMove(board, ROW, COL);
		//�ж���Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
    }
	if (ret == '*')
	{
		printf("���Ӯ��\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ��\n");
	}
	else
	{
		printf("ƽ��\n");
	}
	DisplayBoard(board, ROW, COL);
} 
//�߼����庯��
int main()
{
	srand((unsigned int)time(NULL));//������������������
	int input = 0;
	do
	{
		menu();//��ӡ�˵�
		printf("����������ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		 case 1:
			 game();
			break;
		 case 0:
			 printf("�˳�\n");
			break;
		 default:
			 printf("ѡ�����\n");
			break;
		}

	} while (input);
	return 0;

}
