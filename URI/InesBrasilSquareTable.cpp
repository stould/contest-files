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

Int A, B;

int main(void) {
    cin >> A >> B;

    Int base = gcd(A, B);
    Int best = 100000000000LL;
    vector<Int> use;

    for (int i = 2; i <= sqrt(base); i++) {
        if (base % i == 0) {
            use.push_back(i);
            use.push_back(base / i);
        }
    }

    for (int i = 0; i < (int) use.size(); i++) {
        Int now = use[i];

        if (now * now >= max(A, B) && A % now == 0 && B % now == 0) {
            best = min(best, now);
        }
    }
    
    cout << best << endl;
    return 0;
}
