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

const int MAXN = 120;

int R, N, M;
Int A[MAXN], B[MAXN];

Int pfunc(int base, int e) {
    if (e == 0) return 1;
    if (base == 0) return 0;
    
    Int ans = 1;

    for (int i = 0; i < e; i++) {
        ans *= base;
    }
    
    return ans;
}

Int evalA(int x) {
    Int ans = 0;
    int p = 0;
    
    for (int i = N; i >= 0; i--) {
        ans += A[i] * pfunc(x, p++);
    }

    return ans;
}
Int evalB(int x) {
    Int ans = 0;
    int p = 0;
    
    for (int i = M; i >= 0; i--) {
        ans += B[i] * pfunc(x, p++);
    }

    return ans;
}

int main(void) {
    cin >> R;

    cin >> N;

    for (int i = 0; i <= N; i++) {
        cin >> A[i];
    }

    cin >> M;

    for (int i = 0; i <= M; i++) {
        cin >> B[i];
    }

    cout << evalA(2) <<  " " << evalB(6) << "\n";
    
    int ans = 1;

    cout << ans << "\n";
    
    return 0;
}
