#define _CRT_SECURE_NO_WARNINGS 1
//����Ŀ������СQ�Ĺ�˾����ӵ�m�����񣬵�i��������Ҫxi��ʱ��ȥ��ɣ��Ѷȵȼ�Ϊyi��
//СQӵ��n̨������ÿ̨���������ʱ��zi������ȼ�wi��
//����һ��������ֻ�ܽ���һ̨��������ɣ�������Ÿ����Ļ����������ʱ��С��������Ҫ��ʱ�䣬
//������ɣ�������������񽫻��200*xi + 3 * yi����
//����һ̨��������һ��ֻ�����һ������������Ļ����ȼ�С�ڰ��Ÿ����������Ѷȵȼ���������ɡ�
//СQ���ڽ��쾡���ܵ�ȥ������񣬼���ɵ������������
//����ж��ְ��ŷ�����СQ�����ҵ����������Ǹ�������
//СQ��Ҫ��������������һ�¡�
//
//����������
//�������N + M + 1�У�
//����ĵ�һ��Ϊ����������n��m��1 <= n, m <= 100000), ��ʾ�����������������������
//��������n�У�ÿ��Ϊ��������zi��wi��0 < zi < 1000, 0 <= wi <= 100����
//��ʾÿ̨�����������ʱ��ͼ���ȼ���
//��������m�У�ÿ����������xi��yi��0 < xi <1000, 0 <= yi <= 100����
//��ʾÿ��������Ҫ�����ʱ���������Ѷȵȼ���
//
//���������
//��������������ֱ��ʾ�������ɵ����������ͻ�ȡ�����档
//
//����ʾ����
//1 2
//100 3
//100 2
//100 1
//���ʾ����
//1 20006

#include <iostream>
#include <cstdio>
#include <algorithm>




#define MAX 100001
using namespace std;
//�ṹ��ֱ�����������ͻ�����ʱ��͵ȼ�
struct TaskNode
{
	int x, y;
}task[MAX];

struct MachineNode
{
	int z, w;
}machine[MAX];

//����ͻ����ıȽϺ�������������
static int cmpTask(TaskNode a,TaskNode b)
{
	if (a.x == b.x) return a.y > b.y;
	else return a.x > b.x;
}
static int cmpMachine(MachineNode a, MachineNode b)
{
	if (a.z == b.z) return a.w > b.w;
	else return a.z > b.z;
}

int main()
{
	int m, n;
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) 
		scanf("%d %d", &machine[i].z, &machine[i].w);
	for (i = 0; i < m; i++)
		scanf("%d %d", &task[i].x, &task[i].y);

	sort(machine, machine + n, cmpMachine);
	sort(task, task + m, cmpTask);
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (machine[i].z < task[j].x) continue;
			if (machine[i].z >= task[j].x) 
			{
				
				break;
			}
		}
	}

	return 0;
}