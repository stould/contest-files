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

const int MAXN = 1010;

int M;
string has;

int stp[MAXN];

bool dp[MAXN][15][15];

bool func(int id, int last, int bal) {
    if (id > 0 && (bal <= 0 || bal > 10)) return false;
    if (id == M) return true;

    if (!dp[id][last][bal]) {
        dp[id][last][bal] = true;

        for (int i = 1; i <= 10; i++) if (i != last && has[i - 1] == '1') {
            stp[id] = i;

            bool curr = func(id + 1, i, i - bal);

            if (curr) {
                return true;
            }
        }
    }

    return false;
}

int main(void) {
    //freopen("i.in", "r", stdin);
    cin >> has >> M;

    bool f = func(0, 0, 0);

    memset(dp, false, sizeof(dp));

    if (f) {
        cout << "YES\n";
        for (int i = 0; i < M; i++) {
            cout << stp[i] << " ";
        }
        cout << "\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
