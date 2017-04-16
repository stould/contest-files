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

const int MAXN = 50;

int N, Q;
string A[MAXN], B[MAXN];
int can[30][30];
int dp[10][50];

int func(int len, int last) {
    if (len == N) {
        return 1;
    } else {
        int& ans = dp[len][last];

        if (ans == -1) {
            ans = 0;

            for (int i = 0; i < 6; i++) {                
                for (int j = 0; j < 6; j++) {
                    if (can[i][j] == last) {
                        ans += func(len + 1, i);
                    }
                }
            }
        }        

        return ans;
    }
}

int main(void) {
    cin >> N >> Q;

    memset(can, -1, sizeof(can));
    
    
    for (int i = 0; i < Q; i++) {
        cin >> A[i] >> B[i];

        can[A[i][0] - 'a'][A[i][1] - 'a'] = (B[i][0] - 'a');
    }

    int ans = 0;
    
    memset(dp, -1, sizeof(dp));
    ans += func(1, 0);
    
    cout << ans << "\n";
    
    return 0;
}
