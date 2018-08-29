#define _CRT_SECURE_NO_WARNINGS 1
//【题目描述】小Q的公司最近接到m个任务，第i个任务需要xi的时间去完成，难度等级为yi。
//小Q拥有n台机器，每台机器最长工作时间zi，及其等级wi。
//对于一个任务，它只能交由一台机器来完成，如果安排给它的机器的最长工作时间小于任务需要的时间，
//则不能完成，如果完成这个任务将获得200*xi + 3 * yi收益
//对于一台机器，它一天只能完成一个任务，如果它的机器等级小于安排给它的任务难度等级，则不能完成。
//小Q想在今天尽可能的去完成任务，即完成的任务数量最大。
//如果有多种安排方案，小Q还想找到收益最大的那个方案。
//小Q需要你来帮助他计算一下。
//
//输入描述：
//输入包括N + M + 1行，
//输入的第一行为两个正整数n和m（1 <= n, m <= 100000), 表示机器的数量和任务的数量。
//接下来的n行，每行为两个整数zi和wi（0 < zi < 1000, 0 <= wi <= 100），
//表示每台机器的最大工作时间和及其等级。
//接下来的m行，每行两个整数xi和yi（0 < xi <1000, 0 <= yi <= 100），
//表示每个任务需要的完成时间和任务的难度等级。
//
//输出描述：
//输出两个整数，分别表示最大能完成的任务数量和获取的收益。
//
//输入示例：
//1 2
//100 3
//100 2
//100 1
//输出示例：
//1 20006

#include <iostream>
#include <cstdio>
#include <algorithm>




#define MAX 100001
using namespace std;
//结构体分别用来存任务和机器的时间和等级
struct TaskNode
{
	int x, y;
}task[MAX];

struct MachineNode
{
	int z, w;
}machine[MAX];

//任务和机器的比较函数，用来排序
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