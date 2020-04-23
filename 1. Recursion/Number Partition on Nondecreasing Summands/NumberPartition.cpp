/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2014.10.30
 * OK, 0.250 sec
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 101;

int u[N];

inline int go(int n, int x) {
    if (n == 0)
        return 1;
    if (x > n)
        return 0;

    int res = go(n, x + 1);
    for (int i = 1; i * x <= n; i++)
        if (!u[i]) {
            u[i] = true;
            res += go(n - i * x, x + 1);
            u[i] = false;
        }
    return res;
}

int main() {

    int n;
    cin >> n;
    cout << go(n, 1) << "\n";
    return 0;
}