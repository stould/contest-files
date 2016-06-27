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

int N, X;

int main(void) {
    cin >> N >> X;

    Int has = X;
    int ans = 0;
    
    for (int i = 0; i < N; i++) {
        string S;
        int V;
        
        cin >> S >> V;

        if (S == "+") {
            has += V;
        } else {
            if (has >= V) {
                has -= V;
            } else {
                ans += 1;
            }
        }
    }
    cout << has << " " << ans << "\n";
    return 0;    
}
