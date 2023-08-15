#define _CRT_SECURE_NO_WARNINGS

//���� ��Ȳ���� ���� ���� ���ø� ���� �˰���
//�����ظ� �������� ����

#include <stdio.h>

//�Ž����� ����
//���Կ��� ������ ��� �����ؾ� �� �ݾװ� ������ ������ �־����� ��,
//������ ������ �ּ�ȭ�Ͽ� �Ž������� �����ִ� �׸��� �˰����� ����

void greedyChange(int amount, int coins[], int numCoins) {
    int i, count;

    printf("�Ž�������: ");

    for (i = 0; i < numCoins; i++) {
        count = amount / coins[i];
        amount = amount % coins[i];

        if (count > 0) {
            printf("%d�� %d�� ", coins[i], count);
        }
    }
}

int main()
{
    int amount = 1260;
    int coins[] = { 500, 100, 50, 10 }; //������������ ���ĵǾ��־�� ��.
    int numCoins = sizeof(coins) / sizeof(coins[0]);

    greedyChange(amount, coins, numCoins);

    return 0;
}