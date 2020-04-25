#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e3;
const int MAX_M = 1e3;

int dp[MAX_N + 1][MAX_M + 1];

int main()
{
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int m;
	cin >> m;
	vector <int> b(m);
	for (int i = 0; i < m; i++)
		cin >> b[i];
	/*for (int i = 0; i <= n; i++)
		dp[i][0] = 0;
	for (int j = 0; j <= m; j++)
		dp[0][j] = 0;*/
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[n][m];
	int cur_i = n, cur_j = m;
	vector <int> ans;
	while (cur_i != 0 && cur_j != 0)
	{
		if (a[cur_i - 1] == b[cur_j - 1])
		{
			ans.push_back(a[cur_i - 1]);
			cur_i--;
			cur_j--;
		}
		else if (dp[cur_i - 1][cur_j] > dp[cur_i][cur_j - 1])
			cur_i--;
		else
			cur_j--;
	}
	//system("pause");
	return 0;
}