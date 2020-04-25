#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e3;

int dp[MAX_N], par[MAX_N];

int main()
{
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 1;
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (a[j] < a[i] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
		}
		ans = max(dp[i], ans);
	}
	cout << ans;
	//system("pause");
	return 0;
}