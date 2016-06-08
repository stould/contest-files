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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 100005;

int N, K;
int P[MAXN], D[110];

int main(void) {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> P[i];

        D[P[i] % K] += 1;
    }

    int ans = 0;

    if (D[0] > 0) {
        ans += 1;
    }

    if (K % 2 == 0 && D[K / 2] > 0) {
        ans += 1;
    }
    
    for (int i = 1; i <= K / 2; i++) {
        if (i + i == K || i > K - i) continue;

        ans += max(D[i], D[K - i]);
    }
    
    cout << ans << "\n";
    return 0;
}
