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

const int INF = 10010;
const int MAXN = 20;

int T, N;
int P[MAXN];

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;

        for (int i = 0; i < N; i++) {
            cin >> P[i];
        }
        sort(P, P + N);
        
        int ans = 0;
        int sum = 0;
        int ust = 0;

        for (int i = 0; i < N; i++) {
            if (ust + P[i] > 300) {
                break;
            }
            sum += ust + P[i];
            ust += P[i];
            ans += 1;
        }
        cout << "Case " << t << ": " << ans << " " << sum << "\n";
    }
    return 0;
}
