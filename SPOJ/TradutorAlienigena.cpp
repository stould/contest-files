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

const int MOD = 1000000007;
const int MAXN = 100100;
char num[110], str[MAXN];

int N, M, dp[MAXN];

int rec(int pos) {
    if(pos == M) return 1;
    if(str[pos] == '0') return 0;
    if(dp[pos] != -1) return dp[pos];

    int ans = 0;

    for(int i = pos; i < M; i++) {
        if(i - pos + 1 > N) break;
        if(i - pos + 1 == N) {
            if(strncmp(str+pos, num, N) > 0) {
                break;
            }
        }
        ans = (ans + rec(i + 1)) % MOD;
    }
    return dp[pos] = ans;
}

int main(void) {
    scanf("%s %s", num, str);
    N = strlen(num), M = strlen(str);
    REP(i, M + 1) dp[i] = -1;
    printf("%d\n", rec(0));
    return 0;
}
