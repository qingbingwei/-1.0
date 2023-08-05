//
// Created by 38016 on 2023/8/4.
//

#ifndef SAOLEI_GAME_H
#define SAOLEI_GAME_H
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#endif //SAOLEI_GAME_H
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define easy 10
#define medium 20
#define hard 40

void menu();
void game();
void InitBoard(char arr[ROWS][COLS],int rows,int cols,char set);
void DisplayBoard(char board[ROWS][COLS],int row,int col);
void SetMine(char board[ROWS][COLS],int row, int col);
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);
int get_mine_count(char mine[ROWS][COLS],int x,int y);//统计附近几个雷






