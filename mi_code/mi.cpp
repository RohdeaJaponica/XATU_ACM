#include <iostream>

using namespace std;

void aplusb()
{
	char line[100];

	while (cin.getline(line, 100)) {
		int a, b;
		int i=0;
		while (line[i++] != ' ')
			;
		a = atoi(line);
		b = atoi(line+i);
		cout << a + b << endl;
	}
}

void findSingleNum()
{
	char line[100];
	while (cin.getline(line, 100)) {
		int num = atoi(line);
		int i;
		for (i = 0; line[i] != '\0'; i++)
		{
			if(line[i] == ' ')
				num ^= atoi(line+i+1);
		}
		cout << num << endl;
	}
}

void AsubB_big()
{
	char line[1000001] = { '\0' };
	while (cin.getline(line, 1000001)) {
		int i = 0;
		int num1_left, num1_right;
		int num2_left, num2_right;
		//两个数的左右下标，
		num1_left = 0;
		while (line[i] != ' ')	++i;
		num1_right = i-1;
		const int num1r = num1_right;
		//跳过空格和减号
		i += 3;
		num2_left = i;
		while (line[i] != '\0')	++i;
		num2_right = i-1;
		//左下标不动，右下标由右向左依次相减
		while (num1_right >= num1_left && num2_right>= num2_left)
		{
			//若a的某位大于b的某位，直接相减
			if (line[num1_right] >= line[num2_right])
			{
				line[num1_right] =line[num1_right] - line[num2_right] + '0';
				num1_right--;
				num2_right--;
				continue;
			}
			//若a的某位小于b的某位，借位相减
			else
			{
				char a = 10;
				line[num1_right] = '9' + line[num1_right] - line[num2_right] + 1;
				num1_right--;
				num2_right--;
				int tmp = num1_right;
				while (line[tmp] == '0')
					line[tmp--] = '9';
				--line[tmp];
			}
		}
		//跳过开头的‘0’
		while (line[num1_left] == '0')
			++num1_left;
		//输出
		for (; num1_left <= num1r; num1_left++)
		{
			cout << line[num1_left];
		}
		cout << endl;

	}
}

void test()
{
	AsubB_big();
	//findSingleNum();
	//aplusb();
}




int main()
{
	test();
	return 0;
}