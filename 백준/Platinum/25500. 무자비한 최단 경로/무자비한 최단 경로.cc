#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using ti = tuple<int, int, int>;

int N, K;
vector<vector<pl>> adj;
vector<ll> visited;
void dstra(int sx)
{
    priority_queue<pl, vector<pl>, greater<pl>> pq = priority_queue<pl, vector<pl>, greater<pl>>();
    pq.push({0, sx});
    visited[sx] = 0;
    while (pq.size())
    {
        auto [cc, cx] = pq.top();
        pq.pop();
        if (visited[cx] < cc)
            continue;
        for (auto [nx, nc] : adj[cx])
        {
            if (visited[nx] <= nc + cc)
                continue;
            pq.push({nc + cc, nx});
            visited[nx] = nc + cc;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K;
    adj = vector<vector<pl>>(2 * max(N, K) + 2);
    vector<pair<ti, int>> v;
    visited = vector<ll>(2 * max(N, K) + 2, LLONG_MAX);
    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(make_pair(make_tuple(a, b, c), i));
        adj[i].push_back({c % K + N, c});
        adj[(K - (c % K)) % K + N].push_back({i, c});
    }
    sort(v.begin(), v.end(), [&](pair<ti, int> p1, pair<ti, int> p2)
         { return get<0>(p1.first) < get<0>(p2.first); });
    for (int i = 1; i < N; i++)
    {
        adj[v[i - 1].second].push_back({v[i].second,
                                        get<0>(v[i].first) - get<0>(v[i - 1].first)});
        adj[v[i].second]
            .push_back({v[i - 1].second,
                        get<0>(v[i].first) - get<0>(v[i - 1].first)});
    }
    sort(v.begin(), v.end(), [&](pair<ti, int> p1, pair<ti, int> p2)
         { return get<1>(p1.first) < get<1>(p2.first); });
    for (int i = 1; i < N; i++)
    {
        adj[v[i - 1].second].push_back({v[i].second,
                                        get<1>(v[i].first) - get<1>(v[i - 1].first)});
        adj[v[i].second]
            .push_back({v[i - 1].second,
                        get<1>(v[i].first) - get<1>(v[i - 1].first)});
    }
    dstra(0);
    for (int i = 0; i < N; i++)
    {
        cout << visited[i] << '\n';
    }
}