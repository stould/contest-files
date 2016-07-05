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

    Int ans = 0;
    
    for (int X = 1; X <= N; X++) {
        Int U = A - D + X;
        Int Y = B - C + X;
        Int V = A + Y - D;

        if (min(U, min(Y, V)) >= 1 && max(U, max(Y, V)) <= N) {
            ans += N;
        }
        
        //cout << a << " " << b << " " << c << " " << d << "\n";
        //cout << X << " " << Y << " " << " " << U << " " << V << "\n\n";
    }
    cout << ans << endl;
    return 0;
}
