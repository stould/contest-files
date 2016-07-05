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

const int MAXN = 1010;

int N;
int P[MAXN][MAXN];
int dp[MAXN][MAXN];
bool memo[MAXN][MAXN];

int func(int r, int c) {
    if (r < 0) {
        return 0;
    } else {
        int& ans = dp[r][c];

        if (!memo[r][c]) {
            memo[r][c] = true;
            ans = 0;

            if (c == 0) {
                ans += P[r][c] + func(r - 1, c);
            } else if (r == c) {
                ans += P[r][c] + func(r - 1, c - 1);
            } else {
                ans += P[r][c];
                ans += func(r - 1, c - 1);
                ans += func(r - 1, c); 
            }
            
            return ans;
        } else {
            return 0;
        }
    }
}
int main(void) {
    while (cin >> N && N != 0) {
        memset(memo, false, sizeof(memo));

        int ans = 0;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= i; j++) {
                cin >> P[i][j];
                int now = func(i, j);

                if (now > 0) {
                    ans += func(i, j);
                }

                cout << now << " ";
            }
            cout << endl;
        }

        cout << ans << endl;
    }
    return 0;
}
