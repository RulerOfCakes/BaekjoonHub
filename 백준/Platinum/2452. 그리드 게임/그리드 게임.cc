#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>

using namespace std;

using pi = pair<int, int>;
using ll = long long;

int ans;
int visited[102][102];
int arr[102][102];
vector<int> adj[10101];
int N, M;
int dx[] = {0, -1, 0, 1},
    dy[] = {-1, 0, 1, 0};
int parent[10101];
int bvisited[10101];
int find(int x)
{
    return (x == parent[x] ? x : (parent[x] = find(parent[x])));
}
void uni(int x, int y)
{
    int px = find(x), py = find(y);
    if (px != py)
    {
        parent[py] = px;
    }
}
map<int, int> nmp;
int cn;
void bfs(int sx)
{

    queue<int>
        q;
    q.push(sx);
    int ret = 0;
    bvisited[sx] = 1;
    while (q.size())
    {
        if (ret >= ans)
            break;
        int cx = q.front();
        q.pop();
        if (bvisited[cx] > ans)
            break;
        for (int nx : adj[cx])
        {
            if (!bvisited[nx])
            {
                bvisited[nx] = bvisited[cx] + 1;
                ret = max(ret, bvisited[nx] - 1);
                q.push(nx);
            }
        }
    }
    ans = min(ans, ret);
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    iota(parent, parent + 10100, 0);
    cin >> N >> M;
    for (register int i = 0; i < N; i++)
        for (register int j = 0; j < M; j++)
        {
            cin >> arr[i][j];

            for (register int k = 0; k < 2; k++)
            {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx < 0 || ny < 0)
                    continue;
                if (arr[nx][ny] == arr[i][j])
                {
                    uni(find(nx * M + ny), find(i * M + j));
                }
            }
        }
    for (register int i = 0; i < N; i++)
    {
        for (register int j = 0; j < M; j++)
        {
            int px = find(i * M + j);
            if (!nmp.count(px))
            {
                nmp[px] = ++cn;
            }
            for (register int k = 0; k < 2; k++)
            {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx < 0 || ny < 0)
                    continue;
                if (arr[nx][ny] != arr[i][j])
                {
                    int npx = find(nx * M + ny);
                    if (!nmp.count(npx))
                    {
                        nmp[npx] = ++cn;
                    }

                    adj[nmp[npx]].push_back(nmp[px]);
                    adj[nmp[px]].push_back(nmp[npx]);
                }
            }
        }
    }
    for (register int i = 1; i <= cn; i++)
    {
        adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
    }
    ans = N * M;

    for (register int x = 1; x <= cn; x++)
    {
        memset(bvisited, 0, sizeof(int) * (cn + 2));
        bfs(x);
    }
    cout << ans;
    // 그래프 줄기 절반 값이 답
}