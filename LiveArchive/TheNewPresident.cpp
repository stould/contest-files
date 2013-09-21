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

const int MAXN = 1103;
int T, C, V;

int m[MAXN][MAXN];

int main(void) {
    T = in();

    int i, j, x;

    for ( ; T--; ) {
        C = in();
        V = in();

        for (i = 0; i < V; i++) {
            for (j = 0; j < C; j++) {
                m[i][j] = in();
            }
        }

        int id = 0, cnt = 0;

        map<int, int> mp;
        vector<int> win;

        for (i = 0; i < V; i++) {
            int curr = m[i][0];

            mp[curr] += 1;

            if (mp[curr] > cnt) {
                cnt = mp[curr];
                id = curr;
                win.clear(); win.push_back(curr);
            } else if (mp[curr] == cnt) {
                win.push_back(curr);
            }
        }

        if (cnt > (V / 2)) {
            printf("%d %d", id, 1);
        } else {
            cnt = 0, id = 0;

            mp.clear();

            for (i = 0; i < V; i++) {
                for (j = 1; j < C; j++) {
                    if (m[i][j] == win[0] || m[i][j] == win[1]) {
                        mp[m[i][j]] += 1;

                        if (mp[m[i][j]] > cnt) {
                            cnt = mp[m[i][j]];
                            id = m[i][j];
                        }
                        break;
                    }
                }
            }

            printf("%d %d", id, 2);
        }
        if (T != 0) printf("\n");

    }
    return 0;
}
