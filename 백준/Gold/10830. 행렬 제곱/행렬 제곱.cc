#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <cstring>
#include <climits>

using namespace std;
int N;
long long Bnum;

vector<vector<int>> A;
vector<vector<int>> B;

vector<vector<int>> matrixmul(vector<vector<int>> a, vector<vector<int>> b) {
    vector<vector<int>> result;
    for (int i = 0; i < N; i++) {
        vector<int> v;
        for (int j = 0; j < N; j++) {
            int summ = 0;
            for (int k = 0; k < N; k++) {
                summ += a[i][k] * b[k][j];
            }
            v.push_back(summ%=1000);
        }
        result.push_back(v);
    }
    return result;
}

vector<vector<int>> matrixpower(vector<vector<int>> a, long long n) {
    if (n == 1) {
        vector<vector<int>> result = a;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                result[i][j] %= 1000;
            }
        }
        return result;
    }
    if (n == 2) {
        return matrixmul(a, a);
    }
    if (n % 2 == 1) {
        return matrixmul(a, matrixpower(a, n - 1));
    }
    else {
        return matrixpower(matrixmul(a, a), n / 2);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int a;
    cin >> N >> Bnum;
    for (int i = 0; i < N; i++) {
        vector<int> v;
        for (int j = 0; j < N; j++) {
            cin >> a;
            v.push_back(a);
        }
        A.push_back(v);
    }
    
    B = matrixpower(A, Bnum);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << B[i][j] << " ";
        }
        cout << "\n";
    }
}