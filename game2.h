#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define count_mines 10 // 地雷的个数 -- 10

#define row 9 // 地雷的行 -- 9
#define col 9 // 地雷的列 -- 9

#define ROWS row+2 // 数组的行 -- 11
#define COLS col+2 // 数组的列 -- 11

// mine   地雷
// demine 排雷

// 菜单
void menu();

// 核心
void game();

// 打印数组
void draw(char board[ROWS][COLS]);

// 爆炸探测起始
void combo(int x, int y);

// 向四周检测
void left_combo(int x, int y);

void up_combo(int x, int y);

void down_combo(int x, int y);

void right_combo(int x, int y);