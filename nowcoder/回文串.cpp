//��Ŀ����
//����һ���ַ��������Ƿ���ͨ�����һ����ĸ�����Ϊ���Ĵ���
//�������� :
//һ��һ����Сд��ĸ���ɵ��ַ������ַ�������С�ڵ���10��
//������� :
//�����(YES\NO).
//ʾ��1
//����
//����
//coco
//���
//����
//YES


#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

bool test(string s)
{
	char str[20] = { 0 };
	memcpy(str, s.c_str(),s.size());
	
	int left, right;
	int len = strlen(str);
	left = 0;
	right = len - 1;

	while (str[left] == str[right] && left < right)
	{
		left++; right--;
	}
	if (left >= right) return true;
	int newl = left, newr = right;
	left++;
	while (str[left] == str[right] && left < right)
	{
		left++; right--;
	}
	if (left >= right-1) return true;
	left = newl; right = --newr;
	while (str[left] == str[right] && left < right)
	{
		left++; right--;
	}
	if (left >= right) return true;
	return false;
}

int main()
{
	char str[20] = { 0 };
	while (cin.getline(str, 20))
	{
		if (test(str)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}