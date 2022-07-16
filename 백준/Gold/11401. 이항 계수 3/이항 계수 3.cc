#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;

int T, N, M, R, K;
const int MOD = 1e9 + 7;
const ll LLMOD = 1e9 + 7;

ll power(ll n, ll m)
{
    ll ret = 1;
    while (m)
    {
        if (m & 1)
            ret = ret * n % MOD;
        m >>= 1;
        n = n * n % MOD;
    }
    return ret;
}

ll C(int n, int k)
{
    if (k == 1 || n - k == 1)
        return n;
    if (!k || n == k)
        return 1;
    ll A = 1, B = 1, ret = 0;
    for (int i = n; i >= n - k + 1; i--)
        A = (A * i) % MOD;
    for (int i = 1; i <= k; i++)
        B = (B * i) % MOD;

    return (A * power(B, MOD - 2)) % MOD;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    cout << C(N, K);
}