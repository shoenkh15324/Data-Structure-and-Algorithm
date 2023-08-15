#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//해를 찾는 도중 해가 아니어서 막힌다면, 되돌아가서 다시 해를 찾아가는 기법

//N-Queen 문제
//N-Queen 문제는 N X N 크기의 체스판에 N개의 퀸을 서로 공격할 수 없도록 배치하는 문제이다.
//이 때 퀸은 상하좌우, 대각선 방향으로 체스판의 끝까지 공격할 수 있다.

int n;    // n x n 보드판의 크기 n 
int* col;    // 각 행별로 퀸의 열(column) 위치 

void printQueens()
{
    int i;
    printf(" ");
    for (i = 1; i <= n; i++)
        printf("(%d, %d)\n ", i, col[i]);
    exit(1);
}

int promising(int i) // 유망한지 체크 
{
    int k = 1;
    while (k < i)
    {
        if (col[i] == col[k] || abs(col[i] - col[k]) == abs(i - k)) // 상하좌우, 대각선 상에 있는 지 
            return 0;
        k++;
    }
    return 1;
}

void queens(int i)
{
    int j;

    if (promising(i))    // 유망하다면  
    {
        if (i == n)    // 마지막 행까지 선택이 끝났다면 
        {
            printQueens();    // 퀸의 위치 출력 
            return;
        }
        else    // 아직 끝나지 않았다면 
        {
            for (j = 1; j <= n; j++)    // 모든 열 탐색 
            {
                col[i + 1] = j;
                queens(i + 1);
            }
        }
    }

}

int main()
{
    printf("Input N: ");
    scanf("%d", &n);
    col = (int*)malloc(sizeof(int) * (n + 1));

    /*col[1] = 2 : 1행 2열에 퀸이 있다.
      col[2] = 4 : 2행 4열에 퀸이 있다.
      col[3] = 1 : 3행 1열에 퀸이 있다.
      col[4] = 3 : 4행 3열에 퀸이 있다.*/

    queens(0);
    printf("No solution"); // 해결법이 없을 경우 

    return 0;
}