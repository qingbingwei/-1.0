#include <stdio.h>
#include "game.h"

int main()
{
    srand((unsigned int)time(NULL));//设置随机数起点
    int input = 0;
    do
    {
        menu();
        printf("please choose>");
        scanf("%d",&input);
        switch (input)
        {
            case 1:
                game();
                break;
            case 0:
                printf("exit\n");
                break;
            default:
                printf("wrong\n");
                break;
        }
    }while(input);
    return 0;
}
