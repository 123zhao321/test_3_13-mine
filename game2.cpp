#define _CRT_SECURE_NO_WARNINGS 1
#include "game2.h"

char mine[ROWS][COLS] = { 0 };  // ����
char demine[ROWS][COLS] = { 0 };// ����
int combo_mine[ROWS][COLS] = { 0 }; //δ̽��

// �˵�
void menu()
{
	printf("#############################\n");
	printf("######    1 play      #######\n");
	printf("######    0 exit      #######\n");
	printf("#############################\n");
}

// ��ʼ�����׺͵�������
void clearing_mines()
{
	int i = 0; // ��ʼ��
	int j = 0; // ��ʼ��
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			demine[i][j] = '*';
			mine[i][j] = '0';
		}
	}
}

// ��ӡ����
void draw(char board[ROWS][COLS])
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

// ���õ���
void laying_mine()
{
	int count = count_mines; // ���׵ĸ���
	while (count)
	{
		int i = rand() % row + 1;
		int j = rand() % col + 1;
		if (((i > 0) && (i <= row)) && ((j > 0) && (j <= row)))
		{
			if (mine[i][j] == '0')
			{
				mine[i][j] = '1';
				count--;
			}
		}
	}
}

// ̽�� -- ��ʾ�˴���Χ�ĵ��׸���
void dete(int i, int j)
{
	if ((i == 0 || j == 0) || (i == row + 1 || j == col + 1))
	{
		return;
	}
	int k = 0;
	if (mine[i - 1][j - 1] == '1')	k++;
	if (mine[i - 1][j] == '1')		k++;
	if (mine[i - 1][j + 1] == '1')	k++;
	if (mine[i][j - 1] == '1')		k++;
	if (mine[i][j + 1] == '1')		k++;
	if (mine[i + 1][j - 1] == '1')	k++;
	if (mine[i + 1][j] == '1')		k++;
	if (mine[i + 1][j + 1] == '1')	k++;
	demine[i][j] = '0' + k;
}

// ��Ϸ����
void game()
{
	// ��ʼ�����׺���������
	clearing_mines();

	// ���õ���
	laying_mine();

	// �������----��⻷��
//	printf("-----��������-----\n");
//	draw(mine);
	printf("-----��������-----\n");
	draw(demine);

	// ��ʼ��Ϸ
	int sign_count = 0; // �������̡�*���ĸ���
	while (sign_count - count_mines)
	{
		int i = 0;
		int j = 0;
		printf("\n��������Ҫ���׵�����:>");
		scanf("%d %d", &i, &j);
		
		// �������Ϸ���
		if (((i > 0) && (i <= row)) && ((j > 0) && (j <= col))) // ����Ϸ�
		{
			if (mine[i][j] == '1') // ����
			{
				printf("�㱻ը���ˣ���Ϸ����~\n");
				draw(mine);
				break;
			}
			else // ��ȫ
			{
				dete(i,j);
				
				// �Ƿ���ϱ�ը����
				if (demine[i][j] == '0')
				{
					// ��ʼ��ը
					combo(i, j);
				}
				system("cls");
				draw(demine);
			}
		}
		else
		{
			printf("����Ƿ�������������:>");
			scanf("%d %d", &i, &j);
		}
		sign_count = 0;
		int m = 0;
		int n = 0;
		for (m = 1; m <= row; m++)
		{
			for (n = 1; n <= col; n++)
			{
				if (demine[m][n] == '*')
				{
					sign_count++;
				}
			}
		}
	}
	if (sign_count == count_mines)
	{
		printf("\n��ϲ�㣡���׳ɹ���\n");
		draw(mine);
	}
}

// ��ը̽��
void combo(int x, int y)
{
	// ��ը���
	combo_mine[x][y]++;
	// ̽����Χ
	dete(x - 1, y - 1); // ����
	dete(x - 1, y + 1); // ����
	dete(x + 1, y - 1); // ����
	dete(x + 1, y + 1); // ����
	dete(x - 1, y    ); // ��
	dete(x    , y - 1); // ��
	dete(x + 1, y    ); // ��
	dete(x    , y + 1); // ��

	if (demine[x - 1][y] == '0') // ���ϼ��
	{
		up_combo(x - 1, y);
	}
	if (demine[x + 1][y] == '0') // ���¼��
	{
		down_combo(x + 1, y);
	}
	if (demine[x][y - 1] == '0') // ������
	{
		left_combo(x, y - 1);
	}
	if (demine[x][y + 1] == '0') // ���Ҽ��
	{
		right_combo(x, y + 1);
	}
}


// �Ϸ�
void up_combo(int x, int y)
{
	// ��ը���
	combo_mine[x][y]++;

	dete(x - 1, y - 1); // ����
	dete(x - 1, y + 1); // ����
//	dete(x + 1, y - 1); // ����
//	dete(x + 1, y + 1); // ����
	dete(x - 1, y); // ��
//	dete(x, y - 1); // ��
//	dete(x + 1, y); // ��
//	dete(x, y + 1); // ��

	if ((demine[x][y] == '0') && (demine[x - 1][y] == '0'))
	{
		up_combo(x - 1, y);
	}
}

// ���
void left_combo(int x, int y)
{
	dete(x - 1, y - 1); // ����
//	dete(x - 1, y + 1); // ����
	dete(x + 1, y - 1); // ����
//	dete(x + 1, y + 1); // ����
//	dete(x - 1, y); // ��
	dete(x, y - 1); // ��
//	dete(x + 1, y); // ��
//	dete(x, y + 1); // ��

	if ((demine[x][y] == '0') && (demine[x][y - 1] == '0'))
	{
		left_combo(x, y - 1);
	}
}

// �ұ�
void right_combo(int x, int y)
{
//	dete(x - 1, y - 1); // ����
	dete(x - 1, y + 1); // ����
//	dete(x + 1, y - 1); // ����
	dete(x + 1, y + 1); // ����
//	dete(x - 1, y); // ��
//	dete(x, y - 1); // ��
	dete(x, y + 1); // ��
//	dete(x, y + 1); // ��

	if ((demine[x][y] == '0') && (demine[x][y + 1] == '0'))
	{
		right_combo(x, y + 1);
	}
}

// �·�
void down_combo(int x, int y)
{
//	dete(x - 1, y - 1); // ����
//	dete(x - 1, y + 1); // ����
	dete(x + 1, y - 1); // ����
	dete(x + 1, y + 1); // ����
//	dete(x - 1, y); // ��
//	dete(x, y - 1); // ��
//	dete(x + 1, y); // ��
	dete(x + 1, y); // ��

	if ((demine[x][y] == '0') && (demine[x + 1][y] == '0'))
	{
		left_combo(x + 1, y);
	}
}