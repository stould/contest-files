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
typedef unsigned uint;

int T;
int N, Q;

int main(void) {
    cin >> T;

    int i;

    for ( ; T--; ) {
        cin >> N;

        map<string, double> mp;

        for (i = 0; i < N; i++) {
            string tp;
            double v;
            cin >> tp >> v;
            mp[tp] = v;
        }

        cin >> Q;

        double ans = 0.0;

        for (i = 0; i < Q; i++) {
            string tp;
            int qt;

            cin >> tp >> qt;

            ans += qt * mp[tp];
        }

        printf("R$ %.2lf\n", ans);
    }

    return 0;
}
