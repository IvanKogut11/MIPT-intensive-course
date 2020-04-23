#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void gen(int n, int cnt_opened, int cnt_closed, string ans)
{
	if (cnt_opened + cnt_closed == 2 * n)
	{
		printf("%s\n", ans.c_str());
		return;
	}
	if (cnt_opened < n)
		gen(n, cnt_opened + 1, cnt_closed, ans + '(');
	if (cnt_closed < cnt_opened)
		gen(n, cnt_opened, cnt_closed + 1, ans + ')');
}

int main()
{
	int n;
	scanf("%d", &n);
	gen(n, 0, 0, "");
	system("pause");
	return 0;
}