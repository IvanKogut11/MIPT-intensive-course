#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5;

struct Edge {
	int to, ind;
};

vector <Edge> g[MAX_N];

int ans[MAX_N];
int cnt[MAX_N];
int n;

void dfs(int v, int pr)
{
	cnt[v] = 1;
	for (auto edge : g[v])
	{
		if (edge.to != pr)
		{
			dfs(edge.to, v);
			ans[edge.ind] = cnt[edge.to] * (n - cnt[edge.to]);
			cnt[v] += cnt[edge.to];
		}
	}
}


int main()
{
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back({ y, i });
		g[y].push_back({ x, i });
	}
	dfs(0, -1);
	return 0;
}