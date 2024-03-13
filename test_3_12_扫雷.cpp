#define _CRT_SECURE_NO_WARNINGS 1
#include "game2.h"

int main()
{
	// 时间戳
	srand((unsigned)time(NULL));

	int choose;

	do
	{
		// 开始页面,打印菜单
		menu();

		printf("输入数字选择选项：>");
		scanf("%d", &choose); // 用户的选择

		switch (choose)
		{
			case 0:
				printf("--------游戏结束--------\n");
				break;
			case 1:
				printf("--------游戏开始--------\n");
				game();
				break;
			default:
				printf("输入错误，请重新输入>\n");
				break;
		}
	} while (choose);
	return 0;
}