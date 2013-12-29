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

using namespace std;

typedef long long ll;
typedef unsigned uint;

const int MAXN = 97;
int N, B;
int v[MAXN];

int main(void) {
    int i, j;

    for ( ; scanf("%d%d", &N, &B) == 2 && (N + B != 0); ) {
        for (i = 0; i < B; i++) scanf("%d", &v[i]);

        int M[300]; memset(M, 0, sizeof(M));
        M[0] = 1;

        int cp = 1;

        for (i = 0; i < B; i++) {
            for (j = 0; j < B; j++) {
                int curr = abs(v[i] - v[j]);
                if (!M[curr]) {
                    cp += 1;
                    M[curr] = 1;
                }
            }
        }

        if (cp == N + 1) {
            puts("Y");
        } else {
            puts("N");
        }
    }
    return 0;
}

