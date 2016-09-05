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

int T, N;

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;

        Int ans = 0;
        map<int, int> last;
        int P, finePos = 0;

        for (int i = 0; i < N; i++) {
            cin >> P;

            if (last.find(P) != last.end()) {
                finePos = max(finePos, last[P] + 1);
            }
            last[P] = i;
            long long len = (i - finePos + 1);
            ans += len * (len + 1) / 2;
        }

        cout << ans << "\n";
    }
    return 0;
}
