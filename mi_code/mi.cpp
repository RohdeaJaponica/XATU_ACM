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
		//�������������±꣬
		num1_left = 0;
		while (line[i] != ' ')	++i;
		num1_right = i-1;
		const int num1r = num1_right;
		//�����ո�ͼ���
		i += 3;
		num2_left = i;
		while (line[i] != '\0')	++i;
		num2_right = i-1;
		//���±겻�������±����������������
		while (num1_right >= num1_left && num2_right>= num2_left)
		{
			//��a��ĳλ����b��ĳλ��ֱ�����
			if (line[num1_right] >= line[num2_right])
			{
				line[num1_right] =line[num1_right] - line[num2_right] + '0';
				num1_right--;
				num2_right--;
				continue;
			}
			//��a��ĳλС��b��ĳλ����λ���
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
		//������ͷ�ġ�0��
		while (line[num1_left] == '0')
			++num1_left;
		//���
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