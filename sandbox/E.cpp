#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 1010;

int N, M, K;
int P[MAXN][MAXN];
int A[MAXN][MAXN];
int QI[MAXN][MAXN];
int QJ[MAXN][MAXN];

int main(void) {
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> P[i][j];
        }
    }

    for (int q = 0; q < K; q++) {
        int ai, aj, bi, bj, h, w;
        cin >> ai >> aj >> bi >> bj >> h >> w;

        if (bi < ai || (bi == ai && bj < aj)) {
            swap(ai, bi);
            swap(aj, bj);
        }

        int abs_a_i = bi - ai;
        int abs_a_j = bj - aj;
        int abs_b_i = ai - bi;
        int abs_b_j = aj - bj;

        for (int i = 0; i < h; i++) {
            QI[ai + i][aj] += abs_a_i;
            QI[ai + i][aj + w] -= abs_a_i;

            QI[bi + i][bj] += abs_b_i;
            QI[bi + i][bj + w] -= abs_b_i;
            
            QJ[ai + i][aj] += abs_a_j;
            QJ[ai + i][aj + w] -= abs_a_j;

            QJ[bi + i][bj] += abs_b_j;
            QJ[bi + i][bj + w] -= abs_b_j;
        }        
    }

    for (int i = 1; i <= N; i++) {
        int si = 0;
        int sj = 0;
        
        for (int j = 1; j <= M; j++) {
            si += QI[i][j];
            sj += QJ[i][j];

            cout << i << " " << j << " = " << si << " " << sj << endl;
            
            A[i][j] = P[i + si][j + sj];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
