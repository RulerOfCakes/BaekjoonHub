#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
int N, K;
ll dp[30][30][30];
ll w(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);

    if (dp[a][b][c] != LLONG_MIN)
        return dp[a][b][c];
    ll &ret = dp[a][b][c];
    if (a < b && b < c)
        return ret = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    else
        return ret = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            for (int k = 0; k < 30; k++)
            {
                dp[i][j][k] = LLONG_MIN;
            }
        }
    }
    while (true)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
    }
}