#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <cstring>
#include <climits>

using namespace std;

vector<pair<int, int> > v;
vector<int> sorted;
int dp[505];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    int a, b, longest = 1;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v.push_back(make_pair(b, a));
    }
    sort(v.begin(), v.end());
    dp[1] = v[0].second;
    for (int i = 0; i < N; i++) {
        int target = v[i].first, start = v[i].second;
        for (int j = 1; j <= longest; j++) {
            if (dp[j] == 0) break;
            if (start < dp[j]) {
                dp[j] = start;
                break;
            }
            else if (j == longest) {
                if (start > dp[j]) {
                    dp[j + 1] = start;
                    longest = j + 1;
                }
            }
        }
    }
    cout << N - longest;
}