#include "game.h"
//
// Created by 38016 on 2023/8/4.
//

void menu()
{
    printf("*****************************\n");
    printf("****** 1. play 0. exit ******\n");
    printf("*****************************\n");
}
void game()
{
    printf("start game\n");

    char mine[ROWS][COLS] = {0};//存放雷的信息
    char show[ROWS][COLS] = {0};//存放排查雷的信息
    //初始化为指定内容，mine数组没有雷的时候都是0，show数组在没有排查时都是*
    //初始化函数
    InitBoard(mine,ROWS,COLS,'0');
    InitBoard(show,ROWS,COLS,'*');

    //DisplayBoard(mine,ROW,COL);
    //不能看见雷
    //设置雷
    SetMine(mine,ROW,COL);
    DisplayBoard(show,ROW,COL);
    //排查雷
    FindMine(mine,show,ROW,COL);

}
void InitBoard(char board[ROWS][COLS],int rows,int cols,char set)
{
    int i = 0;
    int j = 0;
    for(i = 0;i < rows;i++)
    {
        for (j = 0;j < cols;j++)
        {
            board[i][j] = set;
        }
    }
}
void DisplayBoard(char board[ROWS][COLS],int row,int col)
{
    int i = 0;
    int j = 0;
    printf("--------------game---------------\n");

    for ( j = 0; j <=col; j++)
    {
        printf("%d ",j);  //打印列号
    }
    printf("\n");
    for(i = 1;i <= row;i++)
    {
        printf("%d ",i);  //打印行号
        for ( j = 1; j <= col; j++)//i，j=1，使用<=方便打印序号
        {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
    printf("--------------game---------------\n");

}
void SetMine(char board[ROWS][COLS],int row, int col)
{
    int count = easy;
    while(count)
    {
        int x = rand()%row + 1;
        int y = rand()%col + 1;

        if(board[x][y] == '0')
        {
            board[x][y] = '1';
            count--;
        }
    }
}
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
    int x = 0;
    int y = 0;
    int win = 0;

    while(win < row * col - easy)
    {
        printf("please scan:>");
        scanf("%d %d",&x,&y);
        if(x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if(show[x][y] != '*')
            {
                printf("wrong,please don\'t scan same place\n");
            }
            else
            {
                if(mine[x][y] == '1')
                {
                    printf("you die\n");
                    DisplayBoard(mine,ROW,COL);
                    break;
                }
                else
                {
                    //统计附近幼几个雷
                    //'1'-'0'=1
                    //'0'-'0'=0
                    win++;
                    int count = get_mine_count(mine,x,y);//统计附近几个雷
                    show[x][y] = count + '0';//转换成数字字符
                    DisplayBoard(show,ROW,COL);
                }
            }

        }
        else
        {
            printf("wrong,please scan again:>");
        }
    }
    if(win == row * col - easy)
    {
        printf("congratulate,you win!\n");
        DisplayBoard(mine,ROW,COL);

    }
}
int get_mine_count(char mine[ROWS][COLS],int x,int y)//统计附近几个雷
{
 return (mine[x - 1][y - 1]+
            mine[x - 1][y]+
            mine[x - 1][y + 1]+
            mine[x][y - 1]+
            mine[x][y + 1]+
            mine[x + 1][y - 1]+
            mine[x + 1][y]+
            mine[x + 1][y + 1]-8*'0');

}
//1.标记功能
//2.展开一片的功能（1.该坐标不是雷；2.该坐标周围没有雷；3.该坐标没有被排查）

