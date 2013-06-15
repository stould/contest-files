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

char dir;
int B, E, much, start, len, counter, mxB = 0, mxE = 0, dp[1000005][2];

int main(void) {
    freopen("greetings.in", "r", stdin);
    freopen("greetings.out", "w", stdout);
    scanf("%d%d ", &B, &E);

    start = 0, counter = 0;

    REP(i, B) {
        scanf("%d %c", &much, &dir);
        if(i == B - 1) much += 1;
        REP(j, much) {
            if(dir == 'R') {
                dp[counter][0] = start++;
            } else {
                dp[counter][0] = start--;
            }
            counter += 1;
            mxB = max(counter, mxB);
        }
    }

    start = 0, counter = 0;

    REP(i, E) {
        scanf("%d %c", &much, &dir);
        if(i == E - 1) much += 1;
        REP(j, much) {
            if(dir == 'R') {
                dp[counter][1] = start++;
            } else {
                dp[counter][1] = start--;
            }
            counter += 1;
            mxE = max(mxE, counter);
        }
    }

    if(dir == 'R') {
        dp[counter][0] = start++;
    } else {
        dp[counter][0] = start--;
    }

    FOR(i, mxB, max(mxB, mxE)) dp[i][0] = dp[i-1][0];
    FOR(i, mxE, max(mxB, mxE)) dp[i][1] = dp[i-1][1];

    int ans = 0;

    REP(i, max(mxB, mxE)) if(i != 0) {
        if(dp[i][0] == dp[i][1]) {
            ans += 1;
            int j = i;
            while(j < max(mxB, mxE) && dp[j][0] == dp[j][1]) {
                j += 1;
            }
            i = j;
        }
    }
    printf("%d\n", ans);
    return 0;
}
