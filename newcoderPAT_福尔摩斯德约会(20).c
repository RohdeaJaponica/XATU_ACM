#include <stdio.h>
#include <string.h>
int main()
{
	int i = 0, j = 0;
	char a[60], b[60], c[60], d[60];
	int week = 0, hour = 0, min = 0;
	gets_s(a, 60);
	gets_s(b, 60);
	gets_s(c, 60);
	gets_s(d, 60);
	
	//gets(a);
	//gets(b);
	//gets(c);
	//gets(d);
	while (a[i] != '\0'&&b[i] != '\0')
	{
		if (a[i] == b[i] && a[i] >= 'A'&&a[i] <= 'G')
		{
			week = a[i] - 'A' + 1;
			char weekend[4] = { 0 };
			switch (week)
			{
			case 1:
			strcpy(weekend, "MON");
				break;
			case 2:
			strcpy(weekend, "TUE");
				break;
			case 3:
			strcpy(weekend, "WED");
				break;
			case 4:
				strcpy(weekend, "THU");
				break;
			case 5:
				strcpy(weekend, "FRI");
				break;
			case 6:
				strcpy(weekend, "SAT");
				break;
			case 7:
				strcpy(weekend, "SUN");
				break;
			default:
				break;
			}
			printf("%s ", weekend);
			i++;
			break;
		}
		i++;
	}
	while (a[i] != '\0'&&b[i] != '\0')
	{
		if (a[i] == b[i] && a[i] >= '0'&&a[i] <= '9')
		{
			hour = a[i] - '0';
			printf("%02d:", hour);
			break;
		}
		if (a[i] == b[i] && a[i] >= 'A'&& a[i] <= 'N')
		{
			hour = a[i] - 'A' + 1 + 9;
			printf("%02d:", hour);
			break;
		}
		i++;
	}
	i = 0;
	while (c[i] != '\0'&&d[i] != '\0')
	{
		if (c[i] == d[i] && c[i] >= 'a'&&c[i] <= 'z')
		{
			min = i;
			printf("%02d", min);
			break;
		}
		i++;
	}
	
	return 0;
 }