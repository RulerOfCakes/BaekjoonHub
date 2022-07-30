#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
int N, Q;
int a, b, c;
int parent[101010];
int find(int x)
{
    if (x == parent[x])
        return x;
    else
        return parent[x] = find(parent[x]);
}

void uni(int a, int b)
{
    int pa = find(a), pb = find(b);
    if (pa != pb)
    {
        parent[pa] = pb;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    vector<pair<pi, int>> v;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b >> c;
        v.push_back({{a, b}, i + 1});
        parent[i + 1] = i + 1;
    }
    sort(v.begin(), v.end());
    pi cc = {-1, 0};
    for (int i = 0; i < N; i++)
    {
        if (cc == make_pair(-1, 0))
        {
            cc = {v[i].first.second, v[i].second};
        }
        else
        {
            if (cc.first >= v[i].first.first)
            {
                uni(cc.second, v[i].second);
                if (cc.first < v[i].first.second)
                {
                    cc = {v[i].first.second, v[i].second};
                }
            }
            else
            {
                cc = {v[i].first.second, v[i].second};
            }
        }
    }
    while (Q--)
    {
        cin >> a >> b;
        int pa = find(a), pb = find(b);
        if (pa == pb)
        {
            cout << "1\n";
        }
        else
            cout << "0\n";
    }
}