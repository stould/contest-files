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

const Int INF = 100101001001000000LL;

int T;
Int N, M, K;

/*
  x.xxxx
  xxx.xx
  ...xxx
  xxxxxx
  xxxxxx
  xxxxxx
 */
int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> M >> K;

        Int ans = INF;

        if (K >= N || K >= M || min(N, M) <= 1) {
            ans = -1;
        }

        if (K < N && 2 * K + 2 < M) {
            chmin(ans, (Int) (1 + (N - 1) / K));
        }
        if (K < M && 2 * K + 2 < N) {
            chmin(ans, (Int) (1 + (M - 1) / K));
        }
        
        
        if (K + 1 < M && 3 * K < M && 2 * K + 1 <= N && 4 * K + 1 <= M) {
            chmin(ans, 5LL);
        }

        cout << "Case #" << t << ": ";
        
        if (ans == INF) {
            ans = -1;
        }

        cout << ans << "\n";
    }
    return 0;
}
