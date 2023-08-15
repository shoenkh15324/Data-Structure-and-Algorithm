#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//해가 존재할 것으로 예상되는 모든 영역을 탐색하는 방법

int main()
{
	//n의 약수의 합
	int n = 0, sum = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0) sum += i;
	}
	printf("%d", sum);

	return 0;
}