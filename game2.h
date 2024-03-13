#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define count_mines 10 // ���׵ĸ��� -- 10

#define row 9 // ���׵��� -- 9
#define col 9 // ���׵��� -- 9

#define ROWS row+2 // ������� -- 11
#define COLS col+2 // ������� -- 11

// mine   ����
// demine ����

// �˵�
void menu();

// ����
void game();

// ��ӡ����
void draw(char board[ROWS][COLS]);

// ��ը̽����ʼ
void combo(int x, int y);

// �����ܼ��
void left_combo(int x, int y);

void up_combo(int x, int y);

void down_combo(int x, int y);

void right_combo(int x, int y);