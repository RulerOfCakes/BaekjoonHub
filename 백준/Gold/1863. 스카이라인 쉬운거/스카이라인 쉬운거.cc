#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
int N;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    vector<pi> v(N);
    int ans = 0;
    stack<int> s;
    for (int i = 0; i < N; i++)
    {
        cin >> v[i].first >> v[i].second;
        while (!s.empty() && s.top() > v[i].second)
        {

            ans++;
            s.pop();
        }
        if (v[i].second != 0 && (s.empty() || s.top() != v[i].second))
            s.push(v[i].second);
    }
    while (s.size())
    {
        s.pop();
        ans++;
    }
    cout << ans;
}