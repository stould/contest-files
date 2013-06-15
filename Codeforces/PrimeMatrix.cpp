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

const int MAXN_P = 500000;
int N, M, matrix[510][510], diff[510][510], memo[MAXN_P] = {0}, row[510], col[510];
set<int> primes;

void build(void) {
    memo[0] = memo[1] = 1;

    for(int i = 2; i <= (int) sqrt(MAXN_P); i++) {
        if(memo[i] == 0) {
            for(int j = i * i; j < MAXN_P; j += i) {
                memo[j] = 1;
            }
        }
    }

    for(int i = 2; i < MAXN_P; i++) if(memo[i] == 0) primes.insert(i);
}

int main(void) {
    scanf("%d%d", &N, &M);

    build();

    REP(i, N) REP(j, M) {
        scanf("%d", &matrix[i][j]);

        if(primes.count(matrix[i][j])) {
            diff[i][j] = 0;
        } else {
            diff[i][j] = (*primes.upper_bound(matrix[i][j])) - matrix[i][j];
        }
    }

    int ans = INT_MAX;

    REP(i, N) REP(j, M) {
        row[i] += diff[i][j];
        col[j] += diff[i][j];
    }

    REP(i, N) ans = min(ans, row[i]);
    REP(i, M) ans = min(ans, col[i]);

    printf("%d\n", ans);

    return 0;
}
