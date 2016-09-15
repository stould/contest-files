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

Int L[2], R[2], K;

int main(void) {
    for (int i = 0; i < 2; i++) {
        cin >> L[i] >> R[i];
    }
    cin >> K;

    Int ans = min(R[0], R[1]) - max(L[0], L[1]) + 1;
    
    if (K >= max(L[0], L[1]) && K <= min(R[0], R[1])) ans -= 1;

    cout << max(0LL, ans) << "\n";
    return 0;    
}
