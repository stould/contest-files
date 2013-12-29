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

const int MAXN = 107;

int N;
char state[MAXN][MAXN];
int pury[MAXN][MAXN], row[MAXN], col[MAXN];

pair<int, int> func (void) {
    int i, j, k;

    priority_queue<pair<int, pair<int, int> > > q;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) if (state[i][j] != 'E') {
            int cnt = 0;

            for (k = 0; k < N; k++) {
                if (!pury[i][k]) cnt += 1;
                if (!pury[k][j]) cnt += 1;
            }

            q.push(make_pair(cnt, make_pair(i, j)));
        }
    }

    return q.top().second;
}

int done (void)  {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (!pury[i][j]) {
                return 1;
            }
        }
    }

    return 0;
}

int main(void) {
    N = in();

    int i, j;

    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf(" %c", &state[i][j]);

            if (state[i][j] == 'E') {
                row[i] += 1;
                col[j] += 1;
            }
        }
    }

    int okA = 0, okB = 0;

    for (i = 0; i < N; i++) {
        if (row[i] == N) {
            okA = 1;
        }
        if (col[i] == N) {
            okB = 1;
        }
    }

    memset(pury, 0, sizeof(pury));

    if (okA && okB) {
        puts("-1");
    } else {
        while (done()) {
            pair<int, int> now = func();
            printf("%d %d\n", now.first + 1, now.second + 1);

            for (i = 0; i < N; i++) {
                pury[now.first][i] = 1;
                pury[i][now.second] = 1;
            }
        }
    }

    return 0;
}
