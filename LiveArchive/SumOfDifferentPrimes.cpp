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

const int MAXN = 1209;
const int MAXK = 17;

int N, K;

int dp[MAXN][MAXK]; //Number of ways to form I using J different primes with the last primes used numner K

vector<int> primes;

void sieve(void) {
    int i, j;
    bool check[MAXN] = {0};

    check[0] = check[1] = 1;

    for (i = 2; i <= (int) sqrt(MAXN); i++) if (!check[i]) {
        for (j = i * i; j < MAXN; j += i) check[j] = 1;
    }

    for (i = 2; i < MAXN; i++) if (!check[i]) {
        primes.push_back(i);
    }
}

int main(void) {
    sieve();

    int i, j, k;

    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;

    for (i = 0; i < primes.size(); i++) {
        for (j = 1120; j >= primes[i]; j--) {
            for (k = 1; k <= 14; k++) {
                dp[j][k] += dp[j - primes[i]][k-1];
            }
        }
    }

    for ( ; scanf("%d%d", &N, &K) == 2 && N + K != 0; ) {
        printf("%d\n", dp[N][K]);
    }
    return 0;
}
