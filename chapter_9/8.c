#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// 掷骰子函数，返回两个骰子的和
int roll_dice(void) {
    int die1 = rand() % 6 + 1;
    int die2 = rand() % 6 + 1;
    printf("You rolled: %d\n", die1 + die2);
    return die1 + die2;
}

bool play_game(void)
{
    int sum = roll_dice();
    if (sum == 7 || sum == 11)
    {
        printf("You win!\n");
        return true;
    }
    else if (sum == 2 || sum == 3 || sum == 12)
    {
        printf("You lose!\n");
        return false;
    }
    else
    {
        int point = sum;
        printf("Your point is %d\n", point);
        while (1)
        {
            sum = roll_dice();
            if (sum == point)
            {
                printf("You win!\n");
                return true;
            }
            else if (sum == 7) {
                printf("You lose!\n");
                return false;
            }
        }
    }
}

//int main()
//{
//    srand((unsigned int)time(NULL));
//    int wins = 0, losses = 0;
//    char play_again;
//
//    do{
//        if (play_game())
//        {
//            wins++;
//        }
//        else
//        {
//            losses++;
//        }
//        printf("Play again? ");
//        scanf(" %c", &play_again);
//    } while (play_again == 'y' || play_again == 'Y');
//    printf("Wins: %d Losses: %d\n", wins, losses);
//    return 0;
//}
int main(void) {
    srand((unsigned int)time(NULL));

    int wins = 0, losses = 0;
    int games = 1000;  // 模拟的局数，可修改

    for (int i = 0; i < games; i++) {
        if (play_game())
            wins++;
        else
            losses++;
    }

    double win_rate = (double)wins / games * 100.0;

    printf("Simulated %d games.\n", games);
    printf("Wins: %d   Losses: %d\n", wins, losses);
    printf("Winning percentage: %.2f%%\n", win_rate);

    return 0;
}

