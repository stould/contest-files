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

using namespace std;

typedef long long Int;
typedef long double ld;

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }

int in(void) {
    int x;
    scanf("%d", &x);
    return x;
}

const int MAXN = 107;
const int MAXT = 1007;
int C, S, E, T;

const int INF = 1010010LL;

int matrix[MAXN][MAXT]; //Max from S to N in time T

int graph[MAXN][MAXN], end[MAXN];

int readInt () {
	bool minus = false;
	int result = 0;
	char ch;

	ch = getchar();

	while (1) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') {
	    minus = true;
    } else {
        result = ch-'0';
    }

	while (1) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result * 10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}


int main(void) {
    int i, j, k;
    for ( ; ; ) {
        C = readInt();
        S = readInt();
        E = readInt();
        T = readInt();

        if (C + S + E + T == 0) break;

        S -= 1;

        for (i = 0; i < C; i++) {
            for (j = 0; j < C; j++) {
                graph[i][j] = readInt();
            }
        }

        for (i = 0; i < E; i++) end[i] = readInt() - 1;

        for (i = 0; i < C; i++) matrix[i][1] = graph[S][i];

        int ans = -INF;

        for (k = 2; k <= T; k++) {
            for (i = 0; i < C; i++) matrix[i][k] = 0;

            for (i = 0; i < C; i++) {
                for (j = 0; j < C; j++) {
                    chmax(matrix[j][k], matrix[i][k - 1] + graph[i][j]);
                }
            }
        }

        for (i = 0; i < E; i++) chmax(ans, matrix[end[i]][T]);

        printf("%d\n", ans);
    }
    return 0;
}
