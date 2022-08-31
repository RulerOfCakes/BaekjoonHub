#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
int N, M;
int arr[52][52];
int dp[52][52];
int chk[52][52];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int sol(int x, int y)
{
    if (dp[x][y] != -1)
        return dp[x][y];
    int &ret = dp[x][y];
    ret = 1;
    int cc = arr[x][y];
    if (!cc)
        return ret = 0;
    chk[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i] * cc, ny = y + dy[i] * cc;
        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;
        if (chk[nx][ny])
            return ret = -1;
        int nc = sol(nx, ny);
        if (nc == -1)
            return ret = -1;
        ret = max(ret, nc + 1);
    }
    chk[x][y] = 0;
    return ret;
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++)
        {
            if (s[j] == 'H')
                continue;
            arr[i][j] = s[j] - '0';
        }
    }
    cout << sol(0, 0);
}