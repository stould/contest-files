#include <bits/stdc++.h>

using namespace std;

const int MAXN = 550;

int N, M;
int A[MAXN][MAXN], B[MAXN][MAXN];
int R[MAXN][MAXN], C[MAXN][MAXN];
int dp[MAXN][MAXN];

int func(int r, int c) {
    if (r < 0 || c < 0) {
        return 0;
    } else {
        int& ans = dp[r][c];
       
        if (ans == -1) {
            ans = max(ans, R[r][c] + func(r - 1, c));
            ans = max(ans, C[r][c] + func(r, c - 1));
        }
       
        return ans;
    }
}

int main() {
    for ( ; scanf("%d%d", &N, &M) == 2 && !(N + M == 0); ) {
        memset(R, 0, sizeof(R));
        memset(C, 0, sizeof(C));
       
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%d", &A[i][j]);

                R[i][j] = A[i][j];
               
                if (j > 0) {
                    R[i][j] += R[i][j - 1];
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%d", &B[i][j]);
               
                C[i][j] = B[i][j];
               
                if (i > 0) {
                    C[i][j] += C[i - 1][j];
                }
            }
        }
       
        memset(dp, -1, sizeof(dp));
       
        printf("%d\n", func(N - 1, M - 1));
    }
    return 0;
}
