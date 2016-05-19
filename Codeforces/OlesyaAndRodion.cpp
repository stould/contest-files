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

int N, T;

int main(void) {
    cin >> N >> T;

    if (T == 10 && N == 1) {
        cout << "-1\n";
    } else {
        if (T == 10) T = 1;

        cout << T;

        for (int i = 0; i < N - 1; i++) {
            cout << "0";
        }
        cout << "\n";
    }
    return 0;
}
