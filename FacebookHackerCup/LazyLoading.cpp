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

int T;
int N, P[MAXN];

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;

        for (int i = 0; i < N; i++) {
            cin >> P[i];
        }

        sort(P, P + N);

        int ans = 0;
        int l = 0;

        for (int i = N - 1; i >= l; i--) {
            int w = P[i];

            while (l < i && w < 50) {
                w += P[i];
                l += 1;
            }
            if (w >= 50) {
                ans += 1;
            }
        }

        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
