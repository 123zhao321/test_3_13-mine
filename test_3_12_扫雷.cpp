#define _CRT_SECURE_NO_WARNINGS 1
#include "game2.h"

int main()
{
	// ʱ���
	srand((unsigned)time(NULL));

	int choose;

	do
	{
		// ��ʼҳ��,��ӡ�˵�
		menu();

		printf("��������ѡ��ѡ�>");
		scanf("%d", &choose); // �û���ѡ��

		switch (choose)
		{
			case 0:
				printf("--------��Ϸ����--------\n");
				break;
			case 1:
				printf("--------��Ϸ��ʼ--------\n");
				game();
				break;
			default:
				printf("�����������������>\n");
				break;
		}
	} while (choose);
	return 0;
}