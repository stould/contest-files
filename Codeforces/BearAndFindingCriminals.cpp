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

const int MAXN = 110;

int N, A;
int P[MAXN];

int main(void) {
    cin >> N >> A;

    A -= 1;
    
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    int ans = 0;
    
    for (int i = 0; i < N; i++) {
        int avail = 0;
        int seen  = 0;

        if (A - i >= 0) {
            avail += 1;
            if (P[A - i] == 1) {
                seen += 1;
            }            
        }
        
        if (A + i < N && A + i != A - i) {
            avail += 1;

            if (P[A + i] == 1) {
                seen += 1;
            }                
        }

        if (avail == seen) {
            ans += seen;
        }
    }
    cout << ans << "\n";
    
    return 0;
}
