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
  
const int MAXN = 45;
const int OFFSET = 16000;
  
int N, F;
int P[MAXN];
bool NN[MAXN], PP[MAXN];
  
int dp[MAXN][5000 * 50 + OFFSET];
  
int func(int pos, int sum) {
    if (pos == N) {
        return sum == F ? 1 : 0;
    } else {
        if (dp[pos][sum + OFFSET] == -1) {
            int A = func(pos + 1, sum + P[pos]);      
            int B = func(pos + 1, sum - P[pos]);
  
            if (A) PP[pos] = true;
            if (B) NN[pos] = true;
  
            dp[pos][sum + OFFSET] = A | B;
        }
		return dp[pos][sum + OFFSET];
    }
}
  
int main(void) {
    for ( ; cin >> N >> F && !(N == 0 && F == 0); ) {
        for (int i = 0; i < N; i++) {
            cin >> P[i];
        }
        for (int i = 0; i < N; i++) {
            NN[i] = PP[i] = false;
        }
  
        memset(dp, -1, sizeof(dp));
  
        int ans = func(0, 0);
  
        if (!ans) {
            cout << "*";
        } else {
            for (int i = 0; i < N; i++) {
                if (PP[i] && NN[i]) {
                    cout << "?";
                } else {
                    if (PP[i]) {
                        cout << "+";
                    } else {
                        cout << "-";
                    }
                }
            }
        }
		cout << "\n";
    }
    return 0;
}
