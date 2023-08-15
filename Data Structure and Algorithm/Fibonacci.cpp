#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//재귀함수로 구현
int fibo(int n)
{
	if (n <= 2) return 1;
	else return fibo(n - 1) + fibo(n - 2);
}

//동적계획법으로 구현
int dp[10000] = { 0 };

int fibo2(int n)
{
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];
	return dp[n];
}

int main()
{
	printf("%d\n", fibo2(30));

	return 0;
}