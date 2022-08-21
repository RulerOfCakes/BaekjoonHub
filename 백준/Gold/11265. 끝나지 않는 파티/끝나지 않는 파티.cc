#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ti = tuple<int, int, int>;

int N, M;
const int INF = 1e9;
ll dp[502][502];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> dp[i][j];
        }
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    while (M--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (dp[a][b] <= c)
            cout << "Enjoy other party\n";
        else
            cout << "Stay here\n";
    }
}