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

int N;
int P[110];

int main(void) {
    cin >> N;

    int i;
    int ans = 0;
    
    for (i = 0; i < N; i++) {
        cin >> P[i];
    }

    i = 0;
    while (i < N && P[i] == 0) {
        i += 1;
    }

    for ( ; i < N; i++) {
        if (P[i] + P[i + 1] != 0) {
            ans += 1;
        } else {
            while (i < N && P[i + 1] == 0) {
                i += 1;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
