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

typedef long long ll;
typedef long double ld;

const int MAXN = 109;

int in(void) { int x; scanf("%d", &x); return x; }

int T, N, M, V_N[MAXN], V_M[MAXN];

int main(void) {
    freopen("i.in", "r", stdin);
    T = in();

    int i, j;

    for ( ; T--; ) {
        M = in(), N = in();

        for (i = 0; i < M; i++) V_M[i] = in();
        for (i = 0; i < N; i++) V_N[i] = in();

        for (i = 0; i < N; i++) {
            int ans = INT_MAX, value = INT_MAX;
            for (j = 0; j < M; j++) {
				int cnt = __builtin_popcount(V_N[i] ^ V_M[j]);
				
				if (cnt < value || (cnt == value && V_M[j] < ans)) {
					ans = V_M[j];
					value = cnt;
				}
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
