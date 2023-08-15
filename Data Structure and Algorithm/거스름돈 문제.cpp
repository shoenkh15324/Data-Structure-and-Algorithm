#define _CRT_SECURE_NO_WARNINGS

//현재 상황에서 가장 좋은 선택만 고르는 알고리즘
//최적해를 구하지는 않음

#include <stdio.h>

//거스름돈 문제
//가게에서 물건을 사고 지불해야 할 금액과 동전의 종류가 주어졌을 때,
//동전의 개수를 최소화하여 거스름돈을 돌려주는 그리디 알고리즘을 구현

void greedyChange(int amount, int coins[], int numCoins) {
    int i, count;

    printf("거스름돈은: ");

    for (i = 0; i < numCoins; i++) {
        count = amount / coins[i];
        amount = amount % coins[i];

        if (count > 0) {
            printf("%d원 %d개 ", coins[i], count);
        }
    }
}

int main()
{
    int amount = 1260;
    int coins[] = { 500, 100, 50, 10 }; //내림차순으로 정렬되어있어야 함.
    int numCoins = sizeof(coins) / sizeof(coins[0]);

    greedyChange(amount, coins, numCoins);

    return 0;
}