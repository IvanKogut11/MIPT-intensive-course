#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector <bool> used;

void printCombination()
{
	for (int i = 0; i < used.size(); i++)
	{
		if (used[i])
			cout << i + 1 << " ";
	}
	cout << "\n";
}

void genAllCombinations(int n, int k, int cur_k, int last_number)
{
	if (cur_k == k)
	{
		printCombination();
		return;
	}
	if (k - cur_k > n - last_number)
		return;
	for (int i = last_number + 1; i < n; i++)
	{
		used[i] = true;
		genAllCombinations(n, k, cur_k + 1, i);
		used[i] = false;
	}
}

int main()
{
	int n, k;
	cin >> n >> k;
	used.assign(n, false);
	genAllCombinations(n, k, 0, -1);
	system("pause");
	return 0;
}