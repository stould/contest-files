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

const int MAXN = 40040;

int x[MAXN];
int dp[MAXN];
int in[MAXN];

int T, P;

int main(void) {
    scanf("%d", &T);

    for( ; T--; ) {
        scanf("%d", &P);

        REP(i, P) {
            scanf("%d", &x[i]);
            dp[i] = in[i] = 1;
        }

        int ans = 1;
        int top = 0;

        dp[0] = INT_MIN;

        REP(i, P) {
            if (x[i] > dp[top]) {
                dp[++top] = x[i];
            } else {
                int low = 0, high = top;
                while (low <= high) {
                    int mid = (low + high) >> 1;
                    if (x[i] > dp[mid]) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                dp[low] = x[i];
            }
            in[i] = top;
            ans = max(ans, top);
        }

        printf("%d\n", ans);
    }
    return 0;
}
