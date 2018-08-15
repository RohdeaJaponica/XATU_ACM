#include <stdio.h>
#include <math.h>
int main()
{
	int i,j,k;
	int count = 1;
	int M, N;
	scanf("%d %d", &M, &N);
	for (i = 2; count <= N;i++)
	{
		for (j = 2; j <= (int)sqrt((double)i); j++)
		{
			if (i % j == 0) break;
		}
		if (j>(int)sqrt((double)i))
		{
			if((count >= M) && ((count-M) % 10 !=9) && (count != N))
				printf("%d ", i);
			if (((count-M) % 10 == 9) || (count == N))
				printf("%d\n", i);
			count++;
		}
	}
	return 0;
}