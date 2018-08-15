#include <stdio.h>
#include <stdlib.h>
int main()
{
	int A, DA, B, DB;
	int countA = 0, countB = 0;
	int retA, retB;
	scanf("%d %d %d %d", &A, &DA, &B, &DB);
	char a[11] = { 0 };
	char b[11] = { 0 };
	
	sprintf(a, "%d", A);
	sprintf(b, "%d", B);
	int i = 0;
	while (a[i] != '\0')
	{
		if (a[i++]-'0' == DA)
			countA++;
	}
	i = 0;
	while (b[i] != '\0')
	{
		if (b[i++] - '0' == DB)
			countB++;
	}
	retA = 0;
	retB = 0;
	for (i = 0; i < countA; i++)
	{	
		retA += DA;
		DA *= 10;
	}
	for (i = 0; i < countB; i++)
	{
		retB += DB;
		DB *= 10;
	}
	printf("%d\n", retA+retB);
	return 0;
}