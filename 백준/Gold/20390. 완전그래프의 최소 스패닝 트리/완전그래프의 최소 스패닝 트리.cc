#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
ll N, A, B, C, D;
ll val[10101], visited[10101];
std::ostream &
operator<<(std::ostream &dest, __int128_t value)
{
    std::ostream::sentry s(dest);
    if (s)
    {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char *d = std::end(buffer);
        do
        {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0)
        {
            --d;
            *d = '-';
        }
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len)
        {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}
inline ll mulmod(ll p, ll q, ll m)
{
    auto a = (__int128_t)p;
    auto b = (__int128_t)q;
    return (ll)((a * b) % (__int128_t)m);
    p %= m;
    q %= m;
    ll r = 0;
    ll w = p;
    while (q)
    {
        if (q & 1)
        {
            r = (r + w) % m;
        }
        w = (w + w) % m;
        q >>= 1;
    }
    return r;
}
set<int> s;
ll prim(int sx)
{
    ll ret = 0;
    visited[sx] = 0;
    // vector<int> all(N);
    // iota(all.begin(), all.end(), 0);
    for (int cnt = 0; cnt < N;)
    {
        ll cc = LLONG_MAX, cx;
        for (int i : s)
        {
            if (visited[i] < cc)
            {
                cc = visited[i];
                cx = i;
            }
        }
        // cout << cnt << endl;
        assert(cc != LLONG_MAX);
        ret += cc;
        s.erase(cx);
        visited[cx] = -1;
        cnt++;
        if (cnt == N)
            break;
        for (int i : s)
        {
            ll nc = i < cx ? (((mulmod(val[i], A, C) + mulmod(val[cx], B, C)) % C) ^ D)
                           : (((mulmod(val[cx], A, C) + mulmod(val[i], B, C)) % C) ^ D);
            // cout << cx << ' ' << i << ' ' << nc << endl;
            if (visited[i] <= nc)
                continue;
            visited[i] = nc;
        }
    }
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;

    cin >> A >> B >> C >> D;
    for (register int i = 0; i < N; i++)
    {
        cin >> val[i];
        s.insert(i);
        visited[i] = LLONG_MAX;
    }
    cout << prim(0);
}