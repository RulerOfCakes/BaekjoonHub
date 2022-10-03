#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pi = pair<int, int>;
int N;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    vector<pi> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());

    for (auto s : v)
    {
        cout << s.first << ' ' << s.second << '\n';
    }
}