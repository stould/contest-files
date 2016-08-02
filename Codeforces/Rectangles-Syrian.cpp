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

const int MAXN = 110;

int T, N;
int cnt[MAXN][MAXN];

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;

        memset(cnt, 0, sizeof(cnt));

        for (int i = 0; i < N; i++) {
            int PI, PJ, PK;
            cin >> PI >> PJ >> PK;

            for (int i = 0; i < PK; i++) {
                for (int j = PI; j < PJ; j++) {
                    cnt[i][j] += 1;
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < MAXN; i++) {
            for (int j = 0; j < MAXN; j++) {
                if (cnt[i][j] > 0) {
                    ans += 1;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
