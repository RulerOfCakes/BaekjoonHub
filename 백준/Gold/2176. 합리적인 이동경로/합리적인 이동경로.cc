#include <bits/stdc++.h>

using namespace std;

using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;

int T, N, M;
vector<vector<pi>> adj;
int dist[1010], dp[1010];
void dstra(int sx)
{
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, sx});
    dist[sx] = 0;
    dp[sx] = 1;
    while (pq.size())
    {
        auto [cc, cx] = pq.top();
        pq.pop();
        if (dist[cx] < cc)
            continue;
        for (auto [nx, nc] : adj[cx])
        {

            if (dist[nx] == -1 || dist[nx] > dist[cx] + nc)
            {
                dist[nx] = dist[cx] + nc;
                pq.push({nc + cc, nx});
            }
            if (dist[nx] != -1 && dist[nx] < cc)
                dp[cx] += dp[nx];
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dist, -1, sizeof(dist));
    cin >> N >> M;
    adj.resize(N + 2);
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    dstra(2);
    cout << dp[1];
}