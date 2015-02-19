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
typedef unsigned uint;

int T;
string S;

Int func(Int x, int k) {
    Int ans = x;

    for (int i = 1; x - (i * k) > 0; i++) {
        ans *= (x - k * i);
    }

    return ans;
}

int main(void) {
    cin >> T;

    for ( ; T--; ) {
        cin >> S;

        Int x = 0;
        int K = 0;

        for (int i = 0; i < (int) S.size(); i++) {
            if (S[i] >= '0' && S[i] <= '9') {
                x = (x * 10) + (S[i] - '0');
            } else {
                K = S.size() - i;
                break;
            }
        }
        cout << func(x, K) << "\n";
    }
    return 0;
}
