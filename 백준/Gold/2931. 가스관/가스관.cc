#include <bits/stdc++.h>

using namespace std;

using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;

int T, N, M;
int sx, sy, ex, ey;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
char arr[30][30];
vector<int> ans;
bool visited[30][30];
int ax = -1, ay = -1;
bool valid(int x, int y, bool um = false)
{
    if (x < 0 || x >= N || y < 0 || y >= M)
        return false;
    if (visited[x][y] == true)
        return false;
    if (um && arr[x][y] == '.')
        return false;
    return true;
}
void dfs(int x, int y)
{
    stack<pi> s;
    s.push({x, y});
    while (s.size())
    {
        auto [cx, cy] = s.top();
        s.pop();
        visited[cx][cy] = 1;
        vector<pi> nv;
        switch (arr[cx][cy])
        {
        case 'M':
            for (int i = 0; i < 4; i++)
            {
                int nx = cx + dx[i], ny = cy + dy[i];
                nv.push_back({nx, ny});
            }
            break;
        case '-':
            nv.push_back({cx, cy - 1});
            nv.push_back({cx, cy + 1});
            break;
        case '|':
            nv.push_back({cx - 1, cy});
            nv.push_back({cx + 1, cy});
            break;
        case '+':
            for (int i = 0; i < 4; i++)
            {
                int nx = cx + dx[i], ny = cy + dy[i];
                nv.push_back({nx, ny});
            }
            break;
        case 'Z':
            for (int i = 0; i < 4; i++)
            {
                int nx = cx + dx[i], ny = cy + dy[i];
                nv.push_back({nx, ny});
            }
            break;
        case '1':
            nv.push_back({cx, cy + 1});
            nv.push_back({cx + 1, cy});
            break;
        case '2':
            nv.push_back({cx - 1, cy});
            nv.push_back({cx, cy + 1});
            break;
        case '3':
            nv.push_back({cx - 1, cy});
            nv.push_back({cx, cy - 1});
            break;
        case '4':
            nv.push_back({cx + 1, cy});
            nv.push_back({cx, cy - 1});
            break;
        default:
            break;
        }
        for (auto [nx, ny] : nv)
        {
            if (!valid(nx, ny, arr[cx][cy] == 'Z' || arr[cx][cy] == 'M'))
                continue;
            if (arr[nx][ny] == '.')
            {
                ax = nx;
                ay = ny;
                if (nx == cx)
                {
                    if (ny == cy + 1)
                        ans.push_back(3);
                    else
                        ans.push_back(1);
                }
                else if (ny == cy)
                {
                    if (nx == cx + 1)
                        ans.push_back(0);
                    else
                        ans.push_back(2);
                }
            }
            else
                s.push({nx, ny});
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'M')
                sx = i, sy = j;
            else if (arr[i][j] == 'Z')
                ex = i, ey = j;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] != '.' && !visited[i][j])
                dfs(i, j);
        }
    }
    if (ax == -1 && ay == -1)
    {
        if (sx == ex && abs(sy - ey) == 2)
        {
            cout << sx + 1 << ' ' << (sy + ey) / 2 + 1 << ' ' << '-';
        }
        else if (sy == ey && abs(sx - ex) == 2)
        {
            cout << (sx + ex) / 2 + 1 << ' ' << sy + 1 << ' ' << '|';
        }
        else
            return -1;
    }
    else
    {
        cout << ax + 1 << ' ' << ay + 1 << ' ';
        if (ans.size() == 2)
        {
            sort(ans.begin(), ans.end());

            if (ans[0] == 1 && ans[1] == 3)
            {
                cout << '-';
            }
            else if (ans[0] == 0 && ans[1] == 2)
            {
                cout << '|';
            }
            else if (ans[0] == 0 && ans[1] == 1)
            {
                cout << 2;
            }
            else if (ans[0] == 0 && ans[1] == 3)
            {
                cout << 3;
            }
            else if (ans[0] == 1 && ans[1] == 2)
            {
                cout << 1;
            }
            else
                cout << 4;
        }
        else if (ans.size() == 4)
        {
            cout << '+';
        }
        else
        {
            // cout << "WOWZRS" << endl;
            // adjacent to M or Z
            for (int i = 0; i < 4; i++)
            {
                int nx = ax + dx[i], ny = ay + dy[i];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                    continue;
                if (arr[nx][ny] == 'M' || arr[nx][ny] == 'Z')
                {
                    ans.push_back(i);
                    break;
                }
            }
            sort(ans.begin(), ans.end());

            if (ans[0] == 1 && ans[1] == 3)
            {
                cout << '-';
            }
            else if (ans[0] == 0 && ans[1] == 2)
            {
                cout << '|';
            }
            else if (ans[0] == 0 && ans[1] == 1)
            {
                cout << 2;
            }
            else if (ans[0] == 0 && ans[1] == 3)
            {
                cout << 3;
            }
            else if (ans[0] == 1 && ans[1] == 2)
            {
                cout << 1;
            }
            else
                cout << 4;
        }
    }
}