#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;
void dfs(const vector<vector<int> >&, int*, bool*, int);
int main()
{
	
	int n,m;
	cin >> n >> m;
	vector <vector<int> > graph(n);

	int *colors = new int [n];
	bool* used = new bool[n];
	for (int i = 0; i < n; i++)
	{
		used[i] = false;
		colors[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		int from,to;
		cin >> from >> to;
		graph[--from].push_back(--to);
	}

	for (int i = 0; i < n; i++) dfs(graph, colors, used, i);
	multimap <int, int> sim;
	for (int i = 0; i < n; i++) 
		sim.insert(colors[i], i);


	
	/*
	1. ��������� ����� �� ������ �������,���� �� ������� ��� �������
	1.1 ������� bool ������ ������������ ������
	2. ��� ������ ������ ������� ���������� ������� � ���� ������� ���������
	2.1 ��� ������� ������� ������ ���� ������������
	2.2 ����� ���������,� ������� ������ ����� ������
	2.2.1 ������� ������ ����� ����� ��� ������
	2.3 ���� ��������� ��������� ���������� �������,�� ������������� ��� ������� � ������ ���� ������� � ����� ����
	3.������� ��� ������� ������ ����� � ����� ������
	*/

}
void dfs(const vector<vector<int> >& gr, int* clr, bool* u, int node)  
{

}