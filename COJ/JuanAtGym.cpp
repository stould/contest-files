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

const double EPS = 1e-7;
const Int MUL = 10000000000LL;

int N;
double P, B;
Int PP, BB;
double A[25];
Int PA[25];
map<Int, int> dp[25];

int func(int pos, Int sum) {
    if (pos >= N) {
        return (sum + BB + EPS) >= PP;
    } else {
        if (dp[pos].find(sum) == dp[pos].end()) {
            int ans = 0;

            ans += func(pos + 1, sum);
            ans += func(pos + 1, sum + 2.0 * PA[pos]);

            dp[pos][sum] = ans;
        }

        return dp[pos][sum];
    }
}

int main(void) {
    cin >> N >> P >> B;

    PP = P * MUL;
    BB = B * MUL;
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        PA[i] = A[i] * MUL;
    }
    
    int ans = 0;

    for (int i = 1; i < (1 << N); i++) {
        Int sum = BB;

        
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                sum += 2 * PA[j];
            }
        }
        if (sum + EPS >= PP) {
            ans += 1;
        }
    }

    if (ans == 0) {
        cout << "Strong\n";
    } else {
        cout << func(0, 0) << "\n";
    }
    return 0;
}
