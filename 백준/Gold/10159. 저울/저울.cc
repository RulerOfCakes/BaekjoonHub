#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using ti = tuple<int, int, int>;

int Q, N, M;
vector<int> adj[102], badj[102];
int visited[102], bvisited[102];
int c;
int dfs(int cx)
{
    int ret = 1;
    visited[cx] = c;
    for (int nx : adj[cx])
    {
        if (visited[nx] == c)
            continue;
        ret += dfs(nx);
    }
    return ret;
}
int bdfs(int cx)
{
    int ret = 1;
    bvisited[cx] = c;
    for (int nx : badj[cx])
    {
        if (bvisited[nx] == c)
            continue;
        ret += bdfs(nx);
    }
    return ret;
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        badj[b].push_back(a);
    }
    for (int i = 1; i <= N; i++)
    {
        c = i;
        cout << N - dfs(i) - bdfs(i) + 1 << '\n';
    }
}