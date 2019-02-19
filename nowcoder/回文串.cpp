//题目描述
//给定一个字符串，问是否能通过添加一个字母将其变为回文串。
//输入描述 :
//一行一个由小写字母构成的字符串，字符串长度小于等于10。
//输出描述 :
//输出答案(YES\NO).
//示例1
//输入
//复制
//coco
//输出
//复制
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