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

int T, K;
string S;

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> S >> K;

        int N = (int) S.size();

        int ans = 0;
        bool valid = true;
        
        for (int i = 0; i <= N - K; i++) {
            if (S[i] == '-') {
                ans += 1;
                
                for (int j = 0; j < K; j++) {
                    if (S[i + j] == '-') {
                        S[i + j] = '+';
                    } else {
                        S[i + j] = '-';
                    }
                }
            }
        }
        for (int i = 0; i < N; i++) {
            if (S[i] == '-') {
                valid = false;
            }
        }

        cout << "Case #" << t << ": ";
        
        
        if (valid) {
            cout << ans << "\n";
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }
    return 0;
}
