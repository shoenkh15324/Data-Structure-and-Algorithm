#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//�ذ� ������ ������ ����Ǵ� ��� ������ Ž���ϴ� ���

int main()
{
	//n�� ����� ��
	int n = 0, sum = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0) sum += i;
	}
	printf("%d", sum);

	return 0;
}