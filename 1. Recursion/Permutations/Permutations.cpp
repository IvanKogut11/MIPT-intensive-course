#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector <int> a;
vector <bool> used;

void printPermutation()
{
	for (int x : a)
		cout << x + 1 << " ";
	cout << "\n";
}

void genAllPermutations(int ind, int n)
{
	if (ind == n)
	{
		printPermutation();
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!used[i])
		{
			used[i] = true;
			a[ind] = i;
			genAllPermutations(ind + 1, n);
			used[i] = false;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	a.assign(n, -1);
	used.assign(n, false);
	genAllPermutations(0, n);
	system("pause");
	return 0;
}