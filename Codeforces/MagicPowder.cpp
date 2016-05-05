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

const int MAXN = 1010;

int N, K;
int A[MAXN];
int B[MAXN];

int main(void) {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    int ans = 0;

    while (1) {
        bool ok = true;
        
        for (int i = 0; i < N; i++) {
            if (K < 0 || (B[i] < A[i] && B[i] + K < A[i])) {
                ok = false;
            }
            int diff = max(0, A[i] - B[i]);
            
            K -= diff;
            B[i] -= A[i];
            B[i] += diff;
            
            if (B[i] < 0) break;
        }
        
        if (!ok) break;

        ans += 1;
    }

    cout << ans << "\n";
    return 0;
}
