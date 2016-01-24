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

uInt L, R, K;

int main(void) {
    cin >> L >> R >> K;

    uInt base = 1;
    
    bool seen = false;

    for ( ; base <= R; base *= K) {
        if (base >= L) {
            cout << base << " ";
            seen = true;
        }
    }
    
    if (!seen) {
        cout << "-1\n";
    } else {
        cout << "\n";
    }
    
	return 0;
}
