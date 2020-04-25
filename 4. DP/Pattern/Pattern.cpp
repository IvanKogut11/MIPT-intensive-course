#include <iostream>

using namespace std;

const int MAX_N = 1e4;

int dp[MAX_N + 4];


int main()
{
	string p, s;
	cin >> p;
	cin >> s;
	int pn = p.size(), sn = s.size();
	dp[0] = 1;
	for (int i = 0; i < pn; i++)
	{
		if (p[i] == '*')
		{
			int l = -1;
			for (int j = 0; j <= sn; j++)
			{
				if (dp[j] == 1)
				{
					l = j;
					break;
				}
			}
			if (l == -1)
				continue;
			for (int j = l + 1; j <= sn; j++)
				dp[j] = 1;
		}
		else
		{
			for (int j = sn; j > 0; j--)
			{
				if (dp[j - 1] && (p[i] == '?' || s[j - 1] == p[i]))
					dp[j] = 1;
				else
					dp[j] = 0;
			}
			dp[0] = 0;
		}
	}
	if (dp[sn])
		cout << "YES";
	else
		cout << "NO";
}