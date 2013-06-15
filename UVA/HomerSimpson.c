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

const int MAXN = 10010;
int N, M, T, dp[MAXN];

int main(void) {
    while(EOF != scanf("%d%d%d", &N, &M, &T)) {
        for(int i = 0; i <= T; i++) dp[i] = -1;
        dp[0] = 0;
        for(int i = min(N, M); i <= T; i++) {
            if(dp[i - N] != -1 && i - N >= 0) dp[i] = max(dp[i], dp[i - N] + 1);
            if(dp[i = M] != -1 && i - M >= 0) dp[i] = max(dp[i], dp[i - M] + 1);
        }
        if(dp[T] != -1) {
            printf("%d\n", dp[T]);
        } else {
            for(int i = T; i >= 0; i--) {
                if(dp[i] > 0) {
                    printf("%d %d\n", dp[i], T - i);
                    break;
                }
            }
        }
    }
    return 0;
}
