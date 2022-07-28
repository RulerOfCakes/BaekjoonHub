#include <bits/stdc++.h>
using namespace std;
int N;
int a, b, c;

struct meeting
{
    int start, end, num;
};

int dp[202020];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    vector<meeting> v(N);
    map<int, int> idxmp;
    vector<int> coords;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b >> c;
        coords.push_back(a);
        coords.push_back(b);
        v[i] = {a,
                b,
                c};
    }
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());
    int rend = coords.size() + 1;
    for (int i = 0; i < coords.size(); i++)
    {
        idxmp[coords[i]] = i + 1;
    }
    for (int i = 0; i < N; i++)
    {
        v[i].start = idxmp[v[i].start];
        v[i].end = idxmp[v[i].end];
    }
    sort(v.begin(), v.end(), [&](meeting m1, meeting m2)
         { return m1.end < m2.end; });
    int ans = 0;
    for (int i = 1, idx = 0; i <= rend && idx < N; i++)
    {
        auto [start, end, num] = v[idx];
        if (end > i)
        {
            dp[i] = max(dp[i], dp[i - 1]);
        }
        else
        {
            dp[i] = max(dp[i], dp[i - 1]);
            dp[i] = max(dp[start] + num, dp[i]);
            ans = max(ans, dp[i]);
            idx++;
            i--;
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
}