#include <cstdio>
#include <iostream>
#include <vector>


using namespace std;

const int MAX_N = 1e5;
const int INF = 1e9 + 7;

vector <pair <int, int>> g[MAX_N];

void Dijkstra(int n, int st, int f)
{
	vector <int> par(n, -1);
	vector <bool> used(n, false);
	vector <int> dist(n, INF);
	dist[st] = 0;
	for (int i = 0; i < n; i++)
	{
		int v = -1;
		for (int u = 0; u < n; u++)
		{
			if (!used[u] && (v == -1 || dist[u] < dist[v]))
				v = u;
		}
		used[v] = true;
		for (pair <int, int> edge : g[v])
		{
			if (!used[edge.first] && dist[v] + edge.second < dist[edge.first])
			{
				dist[edge.first] = dist[v] + edge.second;
				par[edge.first] = v;
			}
		}
	}
	if (dist[f] == INF)
	{
		cout << -1;
		return;
	}
	vector <int> path;
	int cur = f;
	while (cur != -1)
	{
		path.push_back(cur);
		cur = par[cur];
	}
	cout << dist[f] << "\n";
	for (int i = path.size() - 1; i >= 0; i--)
		cout << path[i] + 1 << " ";
}


int main()
{
	int n, m;
	cin >> n >> m;
	int s, f;
	cin >> s >> f;
	s--; f--;
	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		x--;
		y--;
		g[x].push_back({ y, w });
		g[y].push_back({ x, w });
	}
	Dijkstra(n, s, f);
	//system("pause");
	return 0;
}