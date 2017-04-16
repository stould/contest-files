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

const int MAXN = 220;

int K, L1, L2, L3;
int S1[MAXN], S2[MAXN], S3[MAXN];
vector<int> P1[MAXN], P2[MAXN], P3[MAXN];
bool memo[MAXN][MAXN][MAXN];
pair<int, int> dp[MAXN][MAXN][MAXN];

pair<int, int> func(int l1, int l2, int l3) {
    if (memo[l1][l2][l3]) return dp[l1][l2][l3];

    pair<int, int>& ans = dp[l1][l2][l3];
    
    for (int i = 1; i <= K; i++) {
        
    }

    return dp[l1][l2][l3];
}

int main(void) {
    cin >> K >> L1 >> L2 >> L3;

    for (int i = 1; i <= L1; i++) {
        cin >> S1[i];

        P1[S1[i]].push_back(i);
    }
    for (int i = 1; i <= L2; i++) {
        cin >> S2[i];

        P2[S2[i]].push_back(i);
    }
    for (int i = 1; i <= L3; i++) {
        cin >> S3[i];

        P3[S3[i]].push_back(i);
    }

    pair<int, int> ans = make_pair(0, 0);

    for (int i = 1; i <= K; i++) {
        memset(memo, -1, sizeof(memo));

        int a1 = P1[i].empty() ? 0 P1[i][0];
        int a2 = P2[i].empty() ? 0 P2[i][0];
        int a3 = P3[i].empty() ? 0 P3[i][0];
            
        pair<int, int> now = func(a1, a2, a3);
    }
    return 0;
}
