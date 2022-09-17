#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

using pi = pair<int, int>;
using ppi = pair<pi, pi>;
using ll = long long;
int N, M, Q;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (N - j - 1 > i)
                cout << ' ';
            else
                cout << '*';
        }
        cout << '\n';
    }
}