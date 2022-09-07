#include <bits/stdc++.h>

using namespace std;

using pi = pair<long long, long long>;

int T, N;
vector<pi> v;
vector<pi> cvhull;
set<pair<pi, pi>> ost;
int ccw(pi p1, pi p2)
{
    long long ret = p1.first * p2.second - p2.first * p1.second;
    if (ret < 0)
        return -1;
    else if (ret > 0)
        return 1;
    else
        return 0;
}

int ccw(pi p1, pi p2, pi p3)
{
    return ccw({p1.first - p3.first, p1.second - p3.second}, {p2.first - p3.first, p2.second - p3.second});
}

long long dist(pi a, pi b)
{
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

void convex_hull(vector<pi> &arr)
{
    swap(arr[0], *min_element(arr.begin(), arr.end()));
    sort(arr.begin() + 1, arr.end(), [&](const pi &p, const pi &q)
         {
        auto cw = ccw(arr[0], p, q);
        return (cw ? cw > 0 : dist(arr[0], p) < dist(arr[0], q)); });

    for (auto &x : arr)
    {
        while (cvhull.size() > 1 && ccw(cvhull[cvhull.size() - 2], cvhull.back(), x) < 0)
            cvhull.pop_back();
        cvhull.push_back(x);
    }

    int idx = 0;
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] == cvhull.back())
            idx = i;
    for (int i = arr.size() - 1; ccw(cvhull.front(), cvhull.back(), arr[i]) == 0; i--)
        if (cvhull.back() != arr[i] && ccw(cvhull.front(), cvhull.back(), arr[i]) == 0)
            cvhull.push_back(arr[i]);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int L;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        pi temp;
        cin >> temp.first >> temp.second;
        v.push_back(temp);

        if (i)
        {
            ost.insert({v[i - 1], v[i]});
            ost.insert({v[i], v[i - 1]});
        }
    }
    ost.insert({v.back(), v[0]});
    ost.insert({v[0], v.back()});
    cin >> L;
    set<pi> cst;
    for (int i = 0; i < L; i++)
    {
        pi temp;
        cin >> temp.first >> temp.second;
        if (cst.count(temp))
            continue;
        cst.insert(temp);
        v.push_back(temp);
    }
    convex_hull(v);
    int ans = 0;
    // cout << cvhull.size() << endl;
    for (int i = 0; i < cvhull.size(); i++)
    {
        // cout << cvhull[i].first << ' ' << cvhull[i].second << '\n'
        //     << cvhull[(i + 1) % cvhull.size()].first << ' ' << cvhull[(i + 1) % cvhull.size()].second << '\n';
        if (ost.count({cvhull[i], cvhull[(i + 1) % cvhull.size()]}))
            ans++;
    }

    cout << ans;
}