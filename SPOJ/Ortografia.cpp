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

int N, M, dp[25][25];
string dict[1010], chek[110];

bool dist(string& s1, string& s2) {
    int N1 = s1.size(), N2 = s2.size();

    REP(i, N1+1) dp[i][0] = i;
    REP(i, N2+1) dp[0][i] = i;

    FOR(i, 1, N1+1) FOR(j, 1, N2+1) {
        if(s1[i-1] == s2[j-1]) {
            dp[i][j] = dp[i-1][j-1];
        } else {
            dp[i][j] = 1 + min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
        }
    }
    return dp[N1][N2] <= 2;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin >> N >> M;

    REP(i, N) cin >> dict[i];

    REP(i, M) {
        cin >> chek[i];
        REP(j, N) {
            if(dist(dict[j], chek[i])) {
                cout << dict[j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

