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

int P[10];
int A[110];

int main(void) {
    int all = 0;

    
    for (int i = 0; i < 5; i++) {
        cin >> P[i];
        A[P[i]] += 1;
        all += P[i];
    }

    int ans = all;

    for (int i = 1; i <= 100; i++) {
        if (A[i] >= 2) {
            chmin(ans, all - 2 * i);
        }
        if (A[i] >= 3) {
            chmin(ans, all - 3 * i);
        }
    }
    cout << ans << "\n";
    return 0;
}
