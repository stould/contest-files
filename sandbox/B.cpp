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

const int MAXN = 100010;

Int N, H, K;
Int P[MAXN];

int main(void) {
    cin >> N >> H >> K;

    Int ans = 0;
    Int inside = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    for (int i = 0; i < N; i++) {
        if (inside + P[i] <= H) {
            inside += P[i];
        } else {
            Int l = 0LL, h = 10000000000LL, m;
            Int best = 0LL;
            
            while (l <= h) {
                m = (l + h) / 2;
                
                if (inside - K * m + P[i] <= H) {
                    best = m;
                    h = m - 1;
                } else {
                    l = m + 1;
                }
            }

            ans += best;
            inside -= K * best;
            inside = max(inside, 0LL);
            inside += P[i];
        }
    }

    
    ans += ceil(inside / (double) K);
    
    cout << ans << "\n";
    return 0;
}
