#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

using pi = pair<int, int>;
using ppi = pair<pi, pi>;
using ll = long long;
int N, M, Q;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    string s;
    cin >> s;
    vector<int> v;
    stringstream ss(s);
    string temp;
    while (getline(ss, temp, ','))
    {
        v.push_back(stoi(temp));
    }
    while (M--)
    {
        vector<int> nv;
        for (int i = 1; i < v.size(); i++)
        {
            nv.push_back(v[i] - v[i - 1]);
        }
        v = nv;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ',' << v[i];
        else
            cout << v[i];
    }
}