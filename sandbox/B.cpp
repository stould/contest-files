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

Int N, A, B, C, D;

int main(void) {
    cin >> N >> A >> B >> C >> D;

    for (int i = 1; i <= N; i++) {
        Int X = i;
        Int U = -(D - A - X);
        Int Y = -(B + C - X);
        Int V = -(D - Y - A);
    }
    return 0;
}
