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

    char mine[ROWS][COLS] = {0};//����׵���Ϣ
    char show[ROWS][COLS] = {0};//����Ų��׵���Ϣ
    //��ʼ��Ϊָ�����ݣ�mine����û���׵�ʱ����0��show������û���Ų�ʱ����*
    //��ʼ������
    InitBoard(mine,ROWS,COLS,'0');
    InitBoard(show,ROWS,COLS,'*');

    //DisplayBoard(mine,ROW,COL);
    //���ܿ�����
    //������
    SetMine(mine,ROW,COL);
    DisplayBoard(show,ROW,COL);
    //�Ų���
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
        printf("%d ",j);  //��ӡ�к�
    }
    printf("\n");
    for(i = 1;i <= row;i++)
    {
        printf("%d ",i);  //��ӡ�к�
        for ( j = 1; j <= col; j++)//i��j=1��ʹ��<=�����ӡ���
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
                    //ͳ�Ƹ����׼�����
                    //'1'-'0'=1
                    //'0'-'0'=0
                    win++;
                    int count = get_mine_count(mine,x,y);//ͳ�Ƹ���������
                    show[x][y] = count + '0';//ת���������ַ�
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
int get_mine_count(char mine[ROWS][COLS],int x,int y)//ͳ�Ƹ���������
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
//1.��ǹ���
//2.չ��һƬ�Ĺ��ܣ�1.�����겻���ף�2.��������Χû���ף�3.������û�б��Ų飩

