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
 
const int MAX_C = 27;
const int MOD = 1000000007;
 
int T;
char buff[52];
int L;
int dp[51][10][2][MAX_C][MAX_C][MAX_C];
int mark[51][10][2][MAX_C][MAX_C][MAX_C];
int state = 1;
 
int func(int pos, int last, int pref, int a, int b, int c) {
    if (max(abs(a - b), max(abs(a - c), abs(b - c))) > L - pos) return 0LL;    
    if (pos == L) {
        return (a == b && a == c && b == c && a > 0) ? 1LL : 0LL;
    } else {
        int& ans = dp[pos][last][pref][a][b][c];
        
        if (mark[pos][last][pref][a][b][c] != state) {
            mark[pos][last][pref][a][b][c] = state;
            ans = 0;

            int lim = pref ? buff[pos] - '0' : 9;
            
            for (int i = 0; i <= lim; i++) {
                int aa = a;
                int bb = b;
                int cc = c;
 
                if (i == 3) aa += 1;
                if (i == 6) bb += 1;
                if (i == 9) cc += 1;
                
                ans = (ans % MOD) + (func(pos + 1, i, pref && buff[pos] - '0' <= i, aa, bb, cc) % MOD);
            }
        }
        
        return ans % MOD;
    }
}
 
bool isFine(char* arg, int len) {
    int a = 0;
    int b = 0;
    int c = 0;
 
    for (int i = 0; i < len; i++) {
        if (arg[i] == '3') a += 1;
        if (arg[i] == '6') b += 1;
        if (arg[i] == '9') c += 1;
    }
    
    return (a == b && a == c && b == c && a > 0) ? 1LL : 0LL;
}
 
int main(void) {
    scanf("%d", &T);
    
    while (T--) {
        int ans = 0;
        
        scanf("%s", &buff);
        L = (int) strlen(buff);
        ans -= func(0, 0, 1, 0, 0, 0) % MOD;
        state += 1;
 
        if (isFine(buff, L)) {
            ans += 1;
        }
                
        
        scanf("%s", &buff);
        L = (int) strlen(buff);
        ans += func(0, 0, 1, 0, 0, 0) % MOD;
        state += 1;
        
        printf("%d\n", ans);
    }
    return 0;
}
