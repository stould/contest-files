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

const int MAXN = 100005;

int N;
Int P[MAXN];
Int prefix[MAXN];

int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> P[i];

        prefix[i] += P[i];
        
        if (i > 0) {
            prefix[i] += prefix[i - 1];
        }
    }

    Int ans = 0;

    for (int i = 0; i < N; i++) {
        chmax(ans, (prefix[N - 1] - prefix[i]) * prefix[i]);
    }

    cout << ans << "\n";
    
    return 0;
}
