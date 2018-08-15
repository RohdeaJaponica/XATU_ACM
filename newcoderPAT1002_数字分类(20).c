#include<stdio.h>
int main()
{
	int n;
	int i,j;
	int tmp;
	int a[6] = { 0 };
	float a4 = 0;
	int a4num = 0;
	int flag = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &tmp);
		if (tmp % 5 == 0 && tmp % 2 == 0)
			a[1] += tmp;
		if (tmp % 5 == 1)
		{
			if (flag == 0)
			{
				a[2] += tmp;
				flag = 1;
			}
			else
			{
				a[2] -= tmp;
				flag = 0;
			}
		}
		if (tmp % 5 == 2)
			a[3]++;
		if (tmp % 5 == 3)
		{
			a4 += tmp;
			a4num++;
		}
		if (tmp % 5 == 4 && tmp > a[5])
			a[5] = tmp;
	}
	for (j = 1; j <= 4; j++)
	{
		if (j == 4 && a4 != 0)
			printf("%.1f ", a4 / a4num);
		if(j == 4 && a4 == 0)
			printf("N ");
		if (a[j] != 0 && j != 5)
			printf("%d ", a[j]);
		if(a[j] == 0 && j != 4 && j != 5)
			printf("N ");
	}
	if (a[j] != 0)
		printf("%d\n", a[j]);
	if (a[j] == 0)
		printf("N\n");
	return 0;
}