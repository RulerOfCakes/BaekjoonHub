#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

using pi = pair<int, int>;
using ppi = pair<pi, pi>;
using ll = long long;
int N, M, Q;
int group[101010], parent[101010];
set<int> sts[101010];
stack<pi> qry;

int find(int x)
{
    return x == group[x] ? group[x] : group[x] = find(group[x]);
}
void uni(int x, int y)
{
    int px = find(x), py = find(y);
    if (px != py)
    {
        if (sts[px].size() >= sts[py].size())
            swap(px, py);
        group[px] = py;
        for (auto x : sts[px])
        {
            sts[py].insert(x);
        }
        sts[px].clear();
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> Q;
    for (int i = 1; i < N; i++)
    {
        int a;
        cin >> a;
        parent[i + 1] = a;
    }
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        sts[i + 1].insert(a);
        group[i + 1] = i + 1;
    }
    for (int i = 0; i < N + Q - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        qry.push({a, b});
    }
    stack<int> ans;
    while (qry.size())
    {
        auto [cc, cx] = qry.top();
        qry.pop();
        int px = find(cx);
        if (cc == 1)
        {
            uni(cx, parent[cx]);
        }
        else
        {
            ans.push(sts[px].size());
        }
    }
    while (ans.size())
    {
        cout << ans.top() << '\n';
        ans.pop();
    }
}