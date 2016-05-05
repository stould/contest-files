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

int N;
Int K;
Int A[MAXN];
Int B[MAXN];

int main(void) {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    Int ans = 0;
    Int l = 0, h = 3000000000LL, m;

    while (l <= h) {
        m = l + (h - l) / 2;

        Int needed = 0;
        
        for (int i = 0; i < N; i++) {
            needed += max(0LL, m * A[i] - B[i]);

            if (needed > K) {
                break;
            }
        }

        if (needed <= K) {
            ans = max(ans, m);
            l = m + 1;
        } else {
            h = m - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
