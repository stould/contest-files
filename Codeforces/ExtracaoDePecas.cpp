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

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const Int MOD = 1000000007LL;

Int T, N;

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> T;

    while (T--) {
        cin >> N;

        Int A, B;
        
        if (N % 2 == 0) {        
            A = N / 2;
            B = N / 2 + 1;
        } else {
            N += 1;

            A = N / 2;
            B = N / 2;
        }
        
        Int ans = A * B;
        
        ans = ((ans % MOD) + MOD) % MOD;

        cout << ans << endl;
    }
    return 0;
}
