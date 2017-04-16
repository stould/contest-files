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

int N, M;
Int P[100005];

int main(void) {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    sort(P, P + N);

    Int ans = 0;
    
    for (int i = 0; i < M; i++) {
        Int V;
        cin >> V;
        
        int l = 0, h = N - 1, m;
        Int best = 0;
        
        while (l <= h) {
            m = l + (h - l) / 2;

            if (P[m] >= V) {
                best = P[m];
                h = m - 1;
            } else {
                l = m + 1;
            }
        }

        ans += best - V;
    }

    cout << ans << endl;
    return 0;
}
