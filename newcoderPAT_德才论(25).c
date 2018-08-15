#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
	int ID;
	int de;
	int cai;
}Student;

int cmp(const Student *a, const Student *b)
{
	if (
		(a->de + a->cai > b->de + b->cai) ||
		(a->de + a->cai == b->de + b->cai &&
		((a->ID < b->ID&&a->de == b->de) || (a->de > b->de))
			)
		)
		return -1;
	else return 1;
}

int main()
{
	int N;
	int i;
	//std_min最低分 std_de_cai优先分
	int std_min, std_de_cai;
	scanf("%d %d %d", &N, &std_min, &std_de_cai);
	Student *ALL = (Student*)malloc(sizeof(Student)*N);
	Student *part1 = (Student*)malloc(sizeof(Student)*N);
	Student *part2 = (Student*)malloc(sizeof(Student)*N);
	Student *part3 = (Student*)malloc(sizeof(Student)*N);
	Student *part4 = (Student*)malloc(sizeof(Student)*N);
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;
	for (i = 0; i < N; i++)
	{
		scanf("%d %d %d", &(ALL+i)->ID, &(ALL+i)->de, &(ALL+i)->cai);
		//德才均大于优先线
		if (ALL[i].de >= std_de_cai&&ALL[i].cai >= std_de_cai)
		{
			part1[count1++] = ALL[i];
		}
		//德胜才
		else if (ALL[i].de >= std_de_cai&&ALL[i].cai >= std_min&&ALL[i].cai<std_de_cai)
		{
			part2[count2++] = ALL[i];
		}
		//“才德兼亡”但尚有“德胜才”者
		else if (ALL[i].de >= std_min && ALL[i].cai >= std_min && ALL[i].de >= ALL[i].cai)
		{
			part3[count3++] = ALL[i];
		}
		else if (ALL[i].de >= std_min&&ALL[i].cai >= std_min)
		{
			part4[count4++] = ALL[i];
		}
	}
	printf("%d\n", count1+count2+count3+count4);
	qsort(part1, count1, sizeof(Student), cmp);
	for (i = 0; i < count1; i++)
	{
		printf("%d %d %d\n", part1[i].ID, part1[i].de, part1[i].cai);
	}
	qsort(part2, count2, sizeof(Student), cmp);
	for (i = 0; i < count2; i++)
	{
		printf("%d %d %d\n", part2[i].ID, part2[i].de, part2[i].cai);
	}
	qsort(part3, count3, sizeof(Student), cmp);
	for (i = 0; i < count3; i++)
	{
		printf("%d %d %d\n", part3[i].ID, part3[i].de, part3[i].cai);
	}
	qsort(part4, count4, sizeof(Student), cmp);
	for (i = 0; i < count4; i++)
	{
		printf("%d %d %d\n", part4[i].ID, part4[i].de, part4[i].cai);
	}
	free(ALL);
	free(part1);
	free(part2);
	free(part3);
	free(part4);
	return 0;
}