#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
using namespace std;
//Definition for LinkList
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
}*pList;
//Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//��ά�����еĲ���
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

//�滻�ո�
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

//��β��ͷ��ӡ����
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

//�ؽ�������
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

//������ջʵ�ֶ���
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

//��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ��
//���ǳ�֮Ϊ�������ת�� ����һ���Ǽ�����������һ����ת�������ת�������СԪ�ء� 
//��������{ 3,4,5,1,2 }Ϊ{ 1,2,3,4,5 }��һ����ת�����������СֵΪ1�� 
//NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��

//��ת�������С����
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

//쳲���������
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

//������̨�� ������һ�λ�������
class Solution8 {
public:
	int jumpFloor(int number) {
		int n_2 = 0, n_1 = 1, n;
		int i;
		if (number == 0) return n_2;
		for (i = 1; i <= number; i++)
		{
			n = n_2 + n_1;
			n_2 = n_1;
			n_1 = n;
		}
		return n;
	}
};

//������̨�� ������n��
class Solution9
{
public:
	int jumpFloorII(int number) {
		int i;
		int ret = 1;
		for (i = 0; i < number-1; i++)
		{
			ret *= 2;
		}
		return ret;
	}
};

//���θ���
class Solution10
{
public:
	int rectCover(int number) {
		int n_2 = 0, n_1 = 1, n;
		int i;
		if (number == 0)	return n_2;
		if (number == 1) return n_1;
		for (i = 0; i < number; i++)
		{
			n = n_1 + n_2;
			n_2 = n_1;
			n_1 = n;
		}
		return n;
	}
};

//��������1�ĸ���
class Solution11
{
public:
	int  NumberOf1(int n) {
		int ret = 0;
		while (n != 0)
		{
			n = n & (n - 1);
			++ret;
		}
		return ret;
	}
};

//��ֵ�������η�
class Solution12
{
public:
	double Power(double base, int exponent) {
		int i;
		double ret = 1;

		if (fabs(base-0) < 0.0000001)
		{
			if (exponent < 0)
			{
				exit(1);
			}
			return 0;
		}
		for (i = 0; i < abs(exponent); i++)
		{
			ret *= base;
		}
		if (exponent < 0)
			return 1.0 / ret;
		return ret;
	}
};

//��������˳��ʹ����λ��ż��ǰ��
class Solution13 {
public:
	void reOrderArray(vector<int> &array) {
		int left = 0;
		int i = 0;
		for (left = 0; left < array.size(); left++)
		{
			i = left;
			if (array[left] % 2 != 0)
			{
				continue;
			}
			else
			{
				while (i < array.size())
				{
					if (array[i] % 2 == 0)
						i++;
					else					
					{
						while (i > left)
						{
							swap(array[i], array[i - 1]);
							i--;
						}
						break;
					}
				}
				if (i == array.size() - 1) return;
			}
		}
		return;
	}
};

//struct ListNode {
//int val;
//struct ListNode *next;
//ListNode(int x) :
//val(x), next(NULL) {}
//};

//�����е�����K���ڵ�
class Solution14 {
public:
	ListNode * FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL || k == 0) return NULL;
		int len = 0;
		ListNode *cur = pListHead;
		while (cur != NULL)
		{
			++len;
			cur = cur->next;
		}
		if (len < k) return NULL;
		cur = pListHead;
		for (int i = 0; i < len - k; i++)
		{
			cur = cur->next;
		}
		return cur;
	}
};

//��������
class Solution15 {
public:
	ListNode * ReverseList(ListNode* pHead) {
		ListNode *reversed = NULL;
		ListNode *cur = pHead;
		while (pHead != NULL)
		{
			cur = pHead;
			pHead = pHead->next;
			cur->next = reversed;
			reversed = cur;
			
		}
		return reversed;
	}
};

//�ϲ��������������
class Solution16 {
public:
	ListNode * Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode *newList;
		ListNode *newtail;
		if (pHead1 == NULL) return pHead2;
		if (pHead2 == NULL) return pHead1;
		if ((*pHead1).val <= (*pHead2).val)
		{
			newList = pHead1;
			pHead1 = pHead1->next;
			newtail = newList;
		}
		else
		{
			newList = pHead2;
			pHead2 = pHead2->next;
			newtail = newList;
		}

		while (pHead1 != NULL && pHead2 != NULL)
		{
			if ((*pHead1).val <= (*pHead2).val)
			{
				newtail->next = pHead1;
				pHead1 = pHead1->next;
			}
			else
			{
				newtail->next = pHead2;
				pHead2 = pHead2->next;
			}
			newtail = newtail->next;
		}
		if (pHead1 == NULL) newtail->next = pHead2;
		else if (pHead2 == NULL) newtail->next = pHead1;
		return newList;
	}
};

//�����ӽṹ
class Solution17 {
public:
	bool DoesTree1HaveTree2(TreeNode *pRoot1, TreeNode *pRoot2)
	{
		//����2�ߵ���Ҷ�ӽڵ㣬˵��֮ǰ�Ķ���ȡ�
		if (pRoot2 == NULL) return true;
		//����2��û�ߵ�Ҷ�ӽڵ����1�ߵ���Ҷ�ӽڵ㣬˵����ƥ�䡣
		if (pRoot1 == NULL) return false;
		//����Ӧλ�ýڵ�ֵ��ͬ��˵����ƥ�䣬��������ݹ��жϡ�
		if (pRoot1->val != pRoot2->val) return false;
		//������������������ƥ�䣬�򷵻��档
		return DoesTree1HaveTree2(pRoot1->left, pRoot2->left) 
			&& DoesTree1HaveTree2(pRoot1->right, pRoot2->right);
	}
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool ret = false;
		//�����ж��Ƿ�Ϊ��
		if (pRoot2 == NULL || pRoot1 == NULL) return ret;
		//��һ��������1������2�ĵ�һ���ڵ㣬���ҵ��������жϺ���
		if (pRoot1->val == pRoot2->val)
		ret = DoesTree1HaveTree2(pRoot1, pRoot2);
		//����ƥ�䣬������������жϣ�
		if (ret == false) 
			ret = HasSubtree(pRoot1->left, pRoot2);
		if (ret == false) 
			ret = HasSubtree(pRoot1->right, pRoot2);
		return ret;
	}
};

//�������ľ���
class Solution18 {
public:
	void Mirror(TreeNode *pRoot) {
		if (pRoot == NULL) return;
		TreeNode *tmp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = tmp;
		if(pRoot->left != NULL)
			Mirror(pRoot->left);
		if(pRoot->right != NULL)
			Mirror(pRoot->right);
	}
};

//˳ʱ���ӡ����
class Solution19 {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		int row = matrix.size(); int col= matrix[0].size();
		vector<int> ret;
		//�м�Ȧ���к��а�С����
		int circle_times = col < row ? col : row;
		//j��,k����������
		int j = 0, k = 0;
		//rowbegin,colbegin������ʶ��ǰȦ�Ŀ�ʼλ��
		int rowbegin = 0, colbegin = 0;
		//isEnd��ʶ�Ƿ������������Ϊ1*n��n*1����Ҫ�ж�
		int isEnd = 0;
		for (int i = 0; i < (circle_times + 1) / 2; i++)
		{
			if (col - colbegin <= 1 || row - rowbegin <= 1) isEnd = 1;
			//������
			while (k < col)
				ret.push_back(matrix[j][k++]);
			//��Ϊk�����һ�Σ����Ҫ������j�Ѿ�������ˣ���������
			--k;++j;
			//������
			while (j < row)
				ret.push_back(matrix[j++][k]);
			--j;--k;
			//������
			while (k >= colbegin && isEnd != 1)
				ret.push_back(matrix[j][k--]);
			++k;--j;
			//������
			while (j > rowbegin && isEnd != 1)
				ret.push_back(matrix[j--][k]);
			
			--col; --row; 
			k = ++colbegin; 
			j = ++rowbegin;
		}
		return ret;
	}
};

//����min������ջ��min()ʱ�临�Ӷ�ΪO��1��
class Solution20 {
public:
	void push(int value) {
		if (s.empty()) minNum.push(value);
		s.push(value);
		if (minNum.top() > value)
			minNum.push(value);
	}
	void pop() {
		if (minNum.top() == s.top())
			minNum.pop();
		s.pop();
	}
	int top() {
		return s.top();
	}
	int min() {
		return minNum.top();
	}
private:
	stack<int> s;
	stack<int> minNum;
};

//ջ��ѹ�롢��������
class Solution21 {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		stack<int> s;
		vector<int>::iterator itPush = pushV.begin();
		vector<int>::iterator itPop = popV.begin();
		for (; !popV.empty(); )
		{
			if (!pushV.empty() && *itPop == *itPush)
			{
				itPush = pushV.erase(itPush);
				itPop = popV.erase(itPop);
			}
			else if(!s.empty() && *itPop == s.top())
			{
				itPop = popV.erase(itPop);
				s.pop();
			}
			else if (pushV.size() != 0)
			{
				s.push(*itPush);
				itPush = pushV.erase(itPush);
			}
			else break;
		}
		if (s.empty() && pushV.empty() && popV.empty()) return 1;
		else return 0;
	}
};

//�������Ĳ������
class Solution22 {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> ret;
		//ÿ�ν���ǰ�ڵ�������ӽڵ�����У���֤����˳��
		//���ݶ���˳�����η���
		deque<TreeNode *> tmp;
		if (root == NULL) return ret;
		tmp.push_back(root);
		while (!tmp.empty())
		{
			//��ǰ�ڵ�����в������������ǰ�ڵ���������������
			TreeNode * front = tmp.front();
			ret.push_back(front->val);
			tmp.pop_front();
			if (front->left != NULL)
				tmp.push_back(front->left);
			if (front->right != NULL)
				tmp.push_back(front->right);
		}
		return ret;
	}
};

//�����������ĺ����������
class Solution23 {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {

		if (sequence.size() == 1) return 1;
		if (sequence.size() == 0) return 0;
		int length = sequence.size();
		//vector<int>::iterator end = sequence.end();
		int left_count = 0;
		//�������������д��ڸ��ڵ�� break;
		for (left_count = 0; left_count < length - 1; left_count++)
		{
			if (sequence[left_count] > sequence[length - 1])	break;
		}
		int	i = left_count;
		//������������С�ڸ��ڵ�ģ���������������������ؼ�
		for (; i < length; i++)
		{
			if (sequence[i] < sequence[length -1]) return false;
		}
		//�ж��������Ƿ�Ϊ���������������ж��������Ƿ�Ϊ����������
		bool left = true;
		vector<int> left_Child;
		for (int j = 0; j < left_count; j++)
			left_Child.push_back(sequence[j]);
		if (left_count > 0)
			left = VerifySquenceOfBST(left_Child);

		bool right = true;
		vector<int> right_Child;
		for (int j = 0; j < length - left_count - 1; j++)
			right_Child.push_back( sequence[j + left_count]);
		if (left_count < length - 1)
			right = VerifySquenceOfBST(right_Child);

		return left && right;
	}
};

//�������к�Ϊĳһֵ��·��
class Solution24 {
public:
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		assert(root != NULL);
		//û�õݹ飬ջ������е��Σ���ʵ������ջģ���˵ݹ顣
		//ջs�����������
		stack<TreeNode*> s;
		//ջsum����������ڵ㵽ĳ�ڵ���ܺ�
		stack<int> sum;
		//ջs_vec����ÿ���ڵ��·��
		stack<vector<int>> s_vec;
		//v��������
		vector<vector<int>> v; //int count=0;
		vector<int> v_tmp;
		TreeNode* p = root;
		int tmp = 0;
		while (p != NULL || !s.empty())
		{
			//����Ϊ����һֱ���������������������
			while (p != NULL)
			{
				v_tmp.push_back(p->val); 
				tmp += p->val;
				sum.push(tmp);
				s_vec.push(v_tmp);
				s.push(p);

				p = p->left;
			}
			//��������Ϊ��
			if (!s.empty())
			{
				//���ж��Ƿ�ΪҶ�ӽڵ㣬���ж�·���ͣ�����������������
				if (s.top()->right == NULL)
				{
					if (sum.top() == expectNumber)
						v.push_back(s_vec.top());
				}
				else
				p = s.top()->right;

				//�������Ľڵ��ջs
				s.pop();
				//��ǰ�ڵ�·������Ϊsumջ��Ԫ�أ���ջ
				tmp = sum.top();
				sum.pop();
				//·��s_vecջͬ��
				v_tmp = s_vec.top();
				s_vec.pop();
			}
		}
		return v;
	}
};

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};

class Solution25 {
public:
	RandomListNode * Clone(RandomListNode* pHead)
	{

	}
};

void test24()
{
	Solution24 a;
	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->right = new TreeNode(12);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(7);
	vector<vector<int>> v;
	v = a.FindPath(root, 22);
}

void test23()
{
	Solution23 a;
	vector<int> v = { 5,7,6,9,11,4,8 };
	cout << a.VerifySquenceOfBST(v);
}

void test21()
{
	Solution21 a;
	
	cout << a.IsPopOrder({ 1,2,3,4,5 }, { 4,3,5,1,2 }) << endl;

}

void test19()
{
	Solution19 a;
	vector<vector<int>> matrix = { { 1,2,3,4 } };
	vector<int> tmp = a.printMatrix(matrix);
	for (int i = 0; i < tmp.size(); i++)
	{
		cout << tmp[i] << " ";
	}
}

void test15()
{
	Solution15 a;
	ListNode *p = new ListNode(1);
	p->next = new ListNode(2);
	p->next->next = new ListNode(3);
	p->next->next->next = NULL;
	p = a.ReverseList(p);
	cout << p->val << endl;
	cout << p->next->val << endl;
	cout << p->next->next->val << endl;
}

void test14()
{
	Solution14 a;
	ListNode *phead = new ListNode(1);
	phead->next = new ListNode(2);
	phead->next->next = new ListNode(3);
	ListNode *ret = a.FindKthToTail(phead, 5);
	if (ret != NULL)
		cout << ret->val << endl;
	else
		cout << "NULL" << endl;
}

void test13()
{
	Solution13 a;
	vector<int> b{ 1,2,3,4,5,6 };
	a.reOrderArray(b);
}

void test12()
{
	Solution12 a;
	cout << a.Power(0, 0) << endl;
	cout << a.Power(-2, -3) << endl;
	cout << a.Power(2, -3) << endl;
}

void test11()
{
	Solution11 a;
	cout << a.NumberOf1(-65535) << endl;
}

void test10()
{
	Solution10 a;
	cout << a.rectCover(2) << endl;
}

void test9()
{
	Solution9 a;
	cout << a.jumpFloorII(3) << endl;
}

void test8()
{
	Solution8 a;
	cout << a.jumpFloor(1) << endl;
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
	test24();
	//test23();
	//test21();
	//test19();
	//test15();
	//test14();
	//test13();
	//test12();
	//test11();
	//test10();
	//test9();
	//test8();
	//test7();
	//test6();
	//test5();
	//test4();
	//test3();
	//test2();
	system("pause");
	return 0;
}