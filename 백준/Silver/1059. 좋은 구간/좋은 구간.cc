#include <bits/stdc++.h>
using namespace std;
int N;
int a, b, c;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    cin >> a;
    sort(v.begin(), v.end());
    auto iter = lower_bound(v.begin(), v.end(), a);
    int ans = 1;
    int a1 = 0, a2 = 0;
    if (*iter == a)
    {
        cout << 0;
        return 0;
    }
    else
    {
        // ans *= *iter - a;
        
        a1 = *iter - a;
        
        
        if (iter == v.begin())
        {
            // ans *= a;
            a2 = a;
        }
        else
        {
            iter--;
            // ans *= a - *iter;
            a2 = a - *iter;
        }
    }
    if (a1 == 1 && a2 == 1)
    {
        cout << 0;
    }
    else
    {
        cout << (a1 - 1) * (a2 - 1) + a2 + a1 - 2;
    }
}