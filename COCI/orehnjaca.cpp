#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1010;
int L, N, P, K, ans1, ans2, m1 = INT_MIN, m2 = INT_MIN, dp[MAXN], cnt[MAXN] = {0};

int main(void) {
    scanf("%d%d", &L, &N);
    memset(dp, -1, sizeof(dp));
    REP(i, N) {
        scanf("%d%d", &P, &K);
        if(K - P > m1) {
            m1 = K - P;
            ans1 = i + 1;
        }
        for(int j = P; j <= K; j++) {
            if(dp[j] != -1) {
                continue;
            }
            dp[j] = i + 1;
            cnt[dp[j]] += 1;
        }
    }
    FOR(i, 1, N+1) if(cnt[i] > m2) { m2 = cnt[i]; ans2 = i; }
    printf("%d\n%d", ans1, ans2);
    return 0;
}
