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

const int MAXN = 22;

int M, K, curr;

int cnt[MAXN];
double cost[MAXN];

double dp[MAXN+5000][25];

double rec(int x, int index) {
    if (x <= 0.0) return 0.0;
    if (index > M) return 10000000.08;

    if (dp[x][index] != -1.0) return dp[x][index];

    dp[x][index] = cost[index] + rec(x - cnt[index], index);

    dp[x][index] = min(dp[x][index], rec(x, index + 1));

    //printf("%d %.2lf\n", x, dp[x][index]);

    return dp[x][index];
}

vector<int> split(string str) {
    istringstream ss(str);
    int tmp;

    vector<int> ans;

    while (ss >> tmp) ans.push_back(tmp);

    return ans;
}

char str[700];


int main(void) {
    int i, j, test = 1;

    for ( ; scanf("%lf%d", &cost[0], &M) == 2; ) {
        cnt[0] = 1;
        for (i = 1; i <= M; i++) {
            scanf("%d%lf", &cnt[i], &cost[i]);
        }

        for (i = 0; i <= 5000; i++) {
            for (j = 0; j < 25; j++) {
                dp[i][j] = -1.0;
            }
        }

        printf("Case %d:\n", test++);

        cin.ignore();
        vector<int> vs = split(string(gets(str)));

        for (i = 0; i < vs.size(); i++) {
            printf("Buy %d for $%.2lf\n", vs[i], rec(vs[i], 0));
        }
    }
    return 0;
}
