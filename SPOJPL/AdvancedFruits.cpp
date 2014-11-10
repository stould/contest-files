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

const int MAXS = 110;

int T = 1;
int N, M;

char S1[MAXS], S2[MAXS];
int dp[MAXS][MAXS];

string track(int i, int j) {
    if (i == 0 && j == 0) {
        return "";
    } else if (i == 0 && j > 0) {
        return track(i, j - 1) + S2[j - 1];
    } else if (i > 0 && j == 0) {
        return track(i - 1, j) + S1[i - 1];
    } else {
        if (S1[i - 1] == S2[j - 1]) {
            return track(i - 1, j - 1) + S1[i - 1];
        } else {
            if (dp[i][j - 1] > dp[i - 1][j]) {
                return track(i, j - 1) + S2[j - 1];
            } else {
                return track(i - 1, j) + S1[i - 1];
            }
        }
    }
}

int main(void) {
    int i, j;

    for ( ; scanf("%s%s", S1, S2) == 2 && S1[0] != '#'; ) {
        N = strlen(S1), M = strlen(S2);

        memset(dp, 0, sizeof(dp));

        for (i = 1; i <= N; i++) {
            for (j = 1; j <= M; j++) {
                if (S1[i - 1] == S2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        printf("%s\n", track(N, M).c_str());
    }
    return 0;
}
