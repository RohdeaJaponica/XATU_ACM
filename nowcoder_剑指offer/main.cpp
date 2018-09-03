#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//二维数组中的查找
class Solution1 {
public:
	bool Find(int target, vector<vector<int> > array) {
		vector<vector<int>>::iterator it_rows;
		vector<int>::iterator it_cols;
		for (it_rows = array.begin(); it_rows != array.end(); it_rows++)
		{
			for (it_cols = (*it_rows).begin(); it_cols != (*it_rows).end(); it_cols++)
			{
				if (*it_cols == target) return 1;
			}
		}
		return 0;
	}
private:
	
};

//替换空格
class Solution2 {
public:
	void replaceSpace(char *str, int length) {
		int i = length;
		int j = length;
		while (i >= 0)
		{
			if (str[i] == ' ')
			{
				j = length+2;
				while (j - 2 != i)
				{
					str[j] = str[j - 2];
					--j;
				}
				str[i] = '%'; 
				str[i + 1] = '2'; 
				str[i + 2] = '0';
				++length;
			}
			--i;
		}
	}
};

  struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
        }
  }*pList;
//从尾到头打印链表
class Solution3 {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> p;
		if (head == NULL) return p;
		ListNode *tail = NULL;
		ListNode *pretail = head;
		while (tail != head->next)
		{
			while (pretail->next != tail)
			{
				pretail = pretail->next;
			}
			p.push_back(pretail->val);
			tail = pretail;
			pretail = head;
		}
		p.push_back(head->val);
		return p;
	}
};

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//重建二叉树
//1 2 4 7 3 5 6 8
class Solution4 {
public:
	TreeNode * reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() == 0) return NULL;
		TreeNode *root = new TreeNode(pre[0]);
		vector<int> leftpre;
		vector<int> leftvin;
		vector<int> rightpre;
		vector<int> rightvin;
		int i = 0;
		for (i = 0; i < (int)pre.size(); i++)
		{
			if (vin[i] == pre[0])
			{
				break;
			}
			leftpre.push_back(pre[i + 1]);
			leftvin.push_back(vin[i]);
		}
		for (i++; i < (int)pre.size(); i++)
		{
			rightpre.push_back(pre[i]);
			rightvin.push_back(vin[i]);
		}
		root->left = reConstructBinaryTree(leftpre, leftvin);
		root->right = reConstructBinaryTree(rightpre, rightvin);
		return root;
	}
};

//用两个栈实现队列
class Solution5
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		while (!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
		int ret = stack2.top();
		stack2.pop();
		while (!stack2.empty())
		{
			stack1.push(stack2.top());
			stack2.pop();
		}
		return ret;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

//把一个数组最开始的若干个元素搬到数组的末尾，
//我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 
//例如数组{ 3,4,5,1,2 }为{ 1,2,3,4,5 }的一个旋转，该数组的最小值为1。 
//NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
class Solution6 {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.empty() == true) return 0;
		int left = 0;
		int right = rotateArray.size() - 1;
		int mid;
		while ((left+1)!=right)
		{
			mid = left + ((right - left) >> 1);
			if (rotateArray[mid] > rotateArray[left])
				left = mid;
			else if (rotateArray[mid] < rotateArray[left])
				right = mid;
			else
			{
				if (rotateArray[left] < rotateArray[right])
					--right;
				else
					++left;
			}
		}
		return rotateArray[left] < rotateArray[right] ? rotateArray[left] : rotateArray[right];
	}
};

class Solution7 {
public:
	int Fibonacci(int n) {
		int i = 0;
		int n_1 = 1; int n_2 = 0; int ret = 0;
		if (n == 0) return n_2;
		if (n == 1) return n_1;
		for (i = 2; i <= n; i++)
		{
			ret = n_1 + n_2;
			n_2 = n_1;
			n_1 = ret;
		}
		return ret;
	}
};

class Solution8 {
public:
	int jumpFloor(int number) {

	}
};

void test8()
{
	Solution8 a;
	a.jumpFloor(5);
}

void test7()
{
	Solution7 a;
	cout << a.Fibonacci(7) << endl;
	//0 1 1 2 3 5 8 13
}

void test6()
{
	Solution6 a;
	vector<int> b{ 1,1,1,0,1 };
	int ret = a.minNumberInRotateArray(b);
	cout << ret << endl;
}

void test5()
{
	Solution5 a;
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	cout << a.pop() << endl;
}

void test4()
{
	Solution4 a;
	vector<int> pre = { 1,2,3,4,5,6,7 };
	vector<int> vin = { 2,1,4,6,5,7,3 };
	TreeNode *ret = a.reConstructBinaryTree(pre, vin);
}

void test3()
{
	ListNode L(3);
	ListNode H(4);
	L.next = &H;
	Solution3 a;
	a.printListFromTailToHead(&L);
}

void test2()
{
	Solution2 a;
	int length = 10;
	char str[20] = " hello";
	a.replaceSpace(str, length);
	cout << str << endl;
}

void test1()
{
	Solution1 a1;
	vector<vector<int>> test(3);
	test[0].push_back(1);
	test[0].push_back(2);
	test[0].push_back(3);
	int tmp = a1.Find(4, test);
	cout << tmp << endl;
}

int main()
{
	test8();
	//test7();
	//test6();
	//test5();
	//test4();
	//test3();
	//test2();
	system("pause");
	return 0;
}