#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5;

vector <int> g[MAX_N];

int dp[MAX_N][2];

void dfs(int v, int pr)
{
	dp[v][1] = 1;
	for (int to : g[v])
	{
		if (to == pr)
			continue;
		dfs(to, v);
		dp[v][1] += dp[to][0];
		dp[v][0] += max(dp[to][1], dp[to][0]);
	}
}


int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(0, -1);
	cout << max(dp[0][0], dp[0][1]);
	return 0;
}