//��Ŀ����
//Fibonacci��������������ģ�
//F[0] = 0
//F[1] = 1
//for each i �� 2: F[i] = F[i - 1] + F[i - 2]
//��ˣ�Fibonacci���о����磺0, 1, 1, 2, 3, 5, 8, 13, ...����Fibonacci�����е������ǳ�ΪFibonacci��������һ��N�����������Ϊһ��Fibonacci����ÿһ������԰ѵ�ǰ����X��ΪX - 1����X + 1�����ڸ���һ����N��������Ҫ���ٲ����Ա�ΪFibonacci����
//�������� :
//����Ϊһ��������N(1 �� N �� 1, 000, 000)
//������� :
//	���һ����С�Ĳ�����ΪFibonacci��"
//	ʾ��1
//	����
//	����
//	15
//	���
//	����
//	2


#include <iostream>
using namespace std;

int main()
{
	int f, f0, f1;
	int i, tmp;
	f0 = 0; f1 = 1;
	
	cin >> i;
	tmp = i;
	while(tmp)
	{
		f = f0 + f1;
		f0 = f1; f1 = f;
		if (i > f) {
			if (i - f < tmp) tmp = i - f;
			else if (tmp != i && i - f > tmp) break;
		}
		else
		{
			if (f - i < tmp)tmp = f - i;
			else if (tmp != i & f - i > tmp) break;
		}
	}
	cout << tmp << endl;
	return 0;
}