#include <stdio.h>
#include <math.h>
#include <string.h>

int arr[1005][1005];

int Leftover(int n, int k) {
    if (arr[n][k] > 0) return arr[n][k];

    int james = Leftover(n - 1, k - 1) + Leftover(n - 1, k);
    if (james >= 10007) return arr[n][k] = james % 10007;
    else return arr[n][k] = james;
}

int main() {
    int N, K;
    scanf("%d%d", &N, &K);

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == j || j == 0) {
                arr[i][j] = 1;

            }
        }
    }

    printf("%d", Leftover(N, K));
}