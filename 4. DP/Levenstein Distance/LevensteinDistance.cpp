#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e4 + 2;
const int MAX_M = 1e4 + 2;

int dp[MAX_N + 1][MAX_M + 1];

int main()
{
	string s, t;
	cin >> s;
	cin >> t;
	int n = s.size(), m = t.size();
	int ce, ci, cr;
	cin >> ce >> ci >> cr;
	for (int i = 1; i <= n; i++)
		dp[i][0] = i * ce;
	for (int j = 1; j <= m; j++)
		dp[0][j] = j * ci;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] = min(dp[i - 1][j] + ce, dp[i][j - 1] + ci);
			if (s[i - 1] == t[j - 1])
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
			else
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + cr);
		}
	}
	cout << dp[n][m];
	//system("pause");
	return 0;
}