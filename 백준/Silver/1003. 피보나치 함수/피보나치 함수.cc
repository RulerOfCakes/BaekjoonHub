#include <bits/stdc++.h>
using namespace std;
int N;
int arr[100];
long long barr[100][100];

void counter(int n)
{
    if (barr[n][0] != -1)
    {
        return;
    }
    if (n == 0)
    {
        barr[n][0] = 1;
        barr[n][1] = 0;
        return;
    }
    else if (n == 1)
    {
        barr[n][1] = 1;
        barr[n][0] = 0;
        return;
    }
    else
    {
        counter(n - 1);
        counter(n - 2);
        barr[n][0] = barr[n - 1][0] + barr[n - 2][0];
        barr[n][1] = barr[n - 1][1] + barr[n - 2][1];
    }
}

int main()
{
    cin >> N;
    memset(barr, -1, sizeof(barr));
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        counter(arr[i]);
        cout << barr[arr[i]][0] << ' ' << barr[arr[i]][1] << '\n';
    }
}