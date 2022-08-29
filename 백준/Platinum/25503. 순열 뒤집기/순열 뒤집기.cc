#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
int N;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    vector<int> v(N);
    stack<pi> s;
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
        int cmin = v[i], cmax = v[i];

        while (s.size() && (s.top().first == cmax + 1 || cmin == s.top().second + 1))
        {
            auto [nmin, nmax] = s.top();
            s.pop();
            cmin = min(cmin, nmin);
            cmax = max(cmax, nmax);
                }

        s.push({cmin, cmax});
    }
    //    cout << s.size() << '\n';
    if (s.size() == 1)
    {
        cout << "YES";
    }
    else
        cout << "NO";
}