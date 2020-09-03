#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;
void dfs(const vector<vector<int> >&, int*, bool*, int);
void wfs(const vector<vector<int> >&, int*, bool*, int);
int main()
{

	int n, m;
	cin >> n >> m;
	vector <vector<int> > graph(n);

	int* colors = new int[n];
	bool* used = new bool[n];
	for (int i = 0; i < n; i++)
	{
		used[i] = false;
		colors[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;
		graph[--from].push_back(--to);
	}

	for (int i = 0; i < n; i++) wfs(graph, colors, used, i);

	multimap <int, int> sim;
	for (int i = 0; i < n; i++)
		sim.insert({ colors[i], i });
	int prev_color = 0;
	for (const auto& p : sim)
	{

		if (p.first != prev_color)cout << endl;
		cout << p.second+1 << " ";
		prev_color = p.first;
	}


	/*
	1. Запускать поиск из каждой вершины,пока не посетим все вершины
	1.1 Завести bool массив посещённости вершин
	2. При каждом поиске красить посещаемые вершины в цвет вершины источника
	2.1 Все вершины вначале должны быть разноцветные
	2.2 Нужна структура,в которой храним цвета вершин
	2.2.1 Завести массив целых чисел для цветов
	2.3 Если приобходе встречаем посещённую вершину,то перекрашиваем все вершины с цветом этой вершины в новый цвет
	3.Выводим все вершины одного цвета в одной строке
	*/

}
void dfs(const vector<vector<int> >& gr, int* clr, bool* u, int node)
{
	if (u[node])return;
	u[node] = true;
	for (auto i : gr[node])
	{
		int old_clr = clr[i];
		for (int j = 0; j < gr.size(); j++) {
			if (clr[j] == old_clr)
				clr[j] = clr[node];
		}
		dfs(gr, clr, u, i);
	}
}
void wfs(const vector<vector<int> >& gr, int* clr, bool* u, int node)
{
	queue<int> numb_versh;
	numb_versh.push(node);
	while (!numb_versh.empty()) 
	{
		int temp=numb_versh.front();
		numb_versh.pop();
		if (u[temp]) continue;
		u[temp] = true;
		for (auto i : gr[temp])
		{
			int old_clr = clr[i];
			for (int j = 0; j < gr.size(); j++) {
				if (clr[j] == old_clr)
					clr[j] = clr[temp];
			}
			numb_versh.push(i);
		}
	}
	

}