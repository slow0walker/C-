#define _CRT_SECURE_NO_WARNINGS 1
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

bool straight, flush, four, three;
bool royal_flush;  // 新增标志位
int pairs;


void read_cards(int hand[NUM_CARDS][2]);
void analyze_hand(int hand[NUM_CARDS][2]);
void print_result(void);

int main(void)
{
    int hand[NUM_CARDS][2];

    for (;;) {
        read_cards(hand);
        analyze_hand(hand);
        print_result();
    }
}

void read_cards(int hand[NUM_CARDS][2])
{
    char ch, rank_ch, suit_ch;
    int rank, suit;
    bool bad_card, duplicate;
    int cards_read = 0;

    while (cards_read < NUM_CARDS) {
        bad_card = false;
        duplicate = false;

        printf("Enter a card: ");

        rank_ch = getchar();
        switch (rank_ch) {
        case '0': exit(EXIT_SUCCESS);
        case '2': rank = 0; break;
        case '3': rank = 1; break;
        case '4': rank = 2; break;
        case '5': rank = 3; break;
        case '6': rank = 4; break;
        case '7': rank = 5; break;
        case '8': rank = 6; break;
        case '9': rank = 7; break;
        case 't': case 'T': rank = 8; break;
        case 'j': case 'J': rank = 9; break;
        case 'q': case 'Q': rank = 10; break;
        case 'k': case 'K': rank = 11; break;
        case 'a': case 'A': rank = 12; break;
        default: bad_card = true;
        }

        suit_ch = getchar();
        switch (suit_ch) {
        case 'c': case 'C': suit = 0; break;
        case 'd': case 'D': suit = 1; break;
        case 'h': case 'H': suit = 2; break;
        case 's': case 'S': suit = 3; break;
        default: bad_card = true;
        }

        while ((ch = getchar()) != '\n')
            if (ch != ' ') bad_card = true;

        if (bad_card) {
            printf("Bad card; ignored.\n");
            continue;
        }

        // 检查重复,如果点数且花色相等，则重复
        for (int i = 0; i < cards_read; i++) {
            if (hand[i][0] == rank && hand[i][1] == suit) {
                duplicate = true;
                break;
            }
        }

        if (duplicate) {
            printf("Duplicate card; ignored.\n");
        }
        else {
            hand[cards_read][0] = rank;
            hand[cards_read][1] = suit;
            cards_read++;
        }
    }
}

void analyze_hand(int hand[NUM_CARDS][2])
{
    int num_in_rank[NUM_RANKS] = { 0 };
    int num_in_suit[NUM_SUITS] = { 0 };
    int num_consec = 0;
    int rank, suit;

    straight = false;
    flush = false;
    four = false;
    three = false;
    royal_flush = false;  // 初始化
    pairs = 0;

    // 统计点数和花色出现次数
    for (int i = 0; i < NUM_CARDS; i++) {
        num_in_rank[hand[i][0]]++;
        num_in_suit[hand[i][1]]++;
    }

    // 检查是否同花
    for (suit = 0; suit < NUM_SUITS; suit++) {
        if (num_in_suit[suit] == NUM_CARDS)
            flush = true;
    }

    // 检查是否顺子
    rank = 0;
    while (rank < NUM_RANKS && num_in_rank[rank] == 0) rank++;
    for (; rank < NUM_RANKS && num_in_rank[rank] > 0; rank++)
        num_consec++;
    if (num_consec == NUM_CARDS)
        straight = true;

    // 检查是否是同花大顺 (10, J, Q, K, A 同花)
    if (flush &&
        num_in_rank[8] == 1 &&  // 10
        num_in_rank[9] == 1 &&  // J
        num_in_rank[10] == 1 && // Q
        num_in_rank[11] == 1 && // K
        num_in_rank[12] == 1)   // A
    {
        royal_flush = true;
    }

    // 检查其他牌型
    for (rank = 0; rank < NUM_RANKS; rank++) {
        if (num_in_rank[rank] == 4) four = true;
        if (num_in_rank[rank] == 3) three = true;
        if (num_in_rank[rank] == 2) pairs++;
    }
}

void print_result(void)
{
    if (royal_flush) printf("Royal flush");       // 新增判断
    else if (straight && flush) printf("Straight flush");
    else if (four) printf("Four of a kind");
    else if (three && pairs == 1) printf("Full house");
    else if (flush) printf("Flush");
    else if (straight) printf("Straight");
    else if (three) printf("Three of a kind");
    else if (pairs == 2) printf("Two pairs");
    else if (pairs == 1) printf("Pair");
    else printf("High card");

    printf("\n\n");
}