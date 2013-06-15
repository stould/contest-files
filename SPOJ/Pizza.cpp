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

const int MAXN = 100010;
// cnt[i] = sum of v[0] .. v[i - 1]
// dp[i] = max sum within interval cnt[0] .. cnt[i - 1]
int N, ans, buff, has, v[MAXN], cnt[MAXN], dp[MAXN];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin >> N;
    ans = buff = has = cnt[0] = dp[0] = 0;
    REP(i, N) {
        cin >> v[i];
        cnt[i+1] = cnt[i] + v[i];
        dp[i+1] = max(dp[i], cnt[i+1]);
    }
    REP(i, N+1) ans = max(ans, (cnt[N] - cnt[i]) + dp[i]);
    REP(i, N) {
        //compare with 0 to check for only negative score
        buff = max(0, buff + v[i]);
        ans = max(ans, buff);
    }
    cout << ans << "\n";
    return 0;
}
