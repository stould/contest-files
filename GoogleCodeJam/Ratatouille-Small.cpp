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

const int MAXN = 55;

int T, N, P;
int C[MAXN];
int S[MAXN][MAXN];

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> P;

        for (int i = 0; i < N; i++) {
            cin >> C[i];
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < P; j++) {
                cin >> S[i][j];
            }
        }

        int ans = 0;
        
        if (N == 1) {
            for (int i = 0; i < P; i++) {
                int qt = S[0][i] / C[i];
            }
        }
    }
    return 0;
}
