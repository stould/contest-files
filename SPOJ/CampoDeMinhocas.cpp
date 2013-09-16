<<<<<<< HEAD
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

const int MAXN = 1007;

int N, M, T = 1;
int sp[MAXN][MAXN];
int dp[MAXN][MAXN][5];

int was[MAXN][MAXN][5];

int func(int i, int j, int kind) {
    if (i == N - 1 && j == M - 1) {
        return sp[i][j];
    }
    if (was[i][j][kind] == 1) {
        return dp[i][j][kind];
    }

    int& ans = dp[i][j][kind] = -(INT_MAX/2);

    was[i][j][kind] = 1;

    if (i + 1 < N) {
        chmax(ans, sp[i][j] + func(i + 1, j, 0));
    }
    if (j + 1 < M && kind != 2) {
        chmax(ans, sp[i][j] + func(i, j + 1, 1));
    }
    if (j - 1 >= 0 && kind != 1) {
        chmax(ans, sp[i][j] + func(i, j - 1, 2));
    }

    return ans;
}

int main(void) {
    int i, j, k;

    for ( ; scanf("%d%d", &N, &M) == 2 && N + M != 0; ) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) {
                scanf("%d", &sp[i][j]);
                for (k = 0; k < 5; k++) {
                    dp[i][j][k] = was[i][j][k] = 0;
                }
            }
        }

        printf("Teste %d\n%d\n\n", T++, func(0, 0, 0));
    }
    return 0;
}
=======
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

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;


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

const int MAXN = 1003;

int N, M, T = 1;
int sp[MAXN][MAXN];
int dp[MAXN][MAXN][3];

const int INF = 1010010010;

int func(int i, int j, int kind) {
    if (i == N - 1 && j == M - 1) {
        return sp[i][j];
    }
    if (dp[i][j][kind] != INF) {
        return dp[i][j][kind];
    }

    int& ans = dp[i][j][kind] = -(INF);

    if (i + 1 < N) {
        chmax(ans, sp[i][j] + func(i + 1, j, 0));
    }
    if (j + 1 < M && kind != 2) {
        chmax(ans, sp[i][j] + func(i, j + 1, 1));
    }
    if (j - 1 >= 0 && kind != 1) {
        chmax(ans, sp[i][j] + func(i, j - 1, 2));
    }
    return ans;
}

int main(void) {
    int i, j, k;

    for ( ; ; ) {
        N = readInt();
        M = readInt();

        if (N + M == 0) break;

        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) {
                sp[i][j] = readInt();
                for (k = 0; k < 3; k++) {
                    dp[i][j][k] = INF;
                }
            }
        }
        printf("Teste %d\n%d\n\n", T++, func(0, 0, 0));
    }
    return 0;
}
>>>>>>> 6a6bf38162909026ef323362ef99b1343934ebfc
