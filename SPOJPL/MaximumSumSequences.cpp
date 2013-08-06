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
#include <numeric>
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

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

const int MAXN = 100007;
const int INF = 1000101001010010LL;
int T, N;

Int V[MAXN];

int main(void) {
    T = in();

    int i;
    Int curr_max = -INF;

    for ( ; T--; ) {
        N = in();

        map<Int, Int> mp;

        for (i = 0; i < N; i++) {
            V[i] = (Int) in();
            chmax(curr_max, (Int) V[i]);
            mp[V[i]] += 1;
        }

        if (curr_max < 0) {
            printf("%lld %lld\n", curr_max, mp[curr_max]);
        } else {
            Int sum = 0, prefix = 0LL, ans = -INF, cnt = 0LL, buff_cnt = 1LL;

            for (i = 0; i < N; i++) {
                sum += V[i];

                Int curr = sum - prefix;

                if (curr > ans) {
                    ans = curr;
                    cnt = buff_cnt;
                } else if (curr == ans) {
                    cnt += buff_cnt;
                }

                if (sum < prefix) {
                    prefix = sum;
                    buff_cnt = 1LL;
                } else if (sum == prefix) {
                    buff_cnt += 1LL;
                }
            }

            printf("%lld %lld\n", ans, cnt);
        }
    }
    return 0;
}
