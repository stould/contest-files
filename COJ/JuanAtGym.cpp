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

const double EPS = 1e-8;
const uInt MUL = 100ULL;

int N;
double P, B;
uInt PP, BB;
double A[25];
uInt PA[25];

int main(void) {
    while (cin >> N >> P >> B) {        
        PP = P * MUL;
        BB = B * MUL;
        
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            PA[i] = A[i] * MUL;
        }
        
        int ans = 0;
        
        for (int i = 0; i < (1 << N); i++) {
            uInt sum = BB;
            
            for (int j = 0; j < N; j++) {
                if (i & (1 << j)) {
                    sum += 2LL * PA[j];
                }
            }
            if (sum >= PP) {
                ans += 1;
            }
        }
        
        if (ans == 0) {
            cout << "Strong\n";
        } else {
            cout << ans << "\n";
        }
    }
    return 0;
}
