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

const int MAXN = 1000032;
const int MOD = 1000000;
int N, x[MAXN];

inline double func(double a) {
    return (a * a);
}

int main(void) {
    x[0] = 1;
    for(int i = 1; i <= MAXN-2; i++) {
        int a = floor(i - sqrt(i));
        int b = floor(log(i));
        int c = floor(i * pow(sin(i), 2));
        x[i] = (x[a] + x[b] + x[c]) % MOD;
    }
    while(scanf("%d", &N) == 1 && N != -1) {
        printf("%d\n", x[N]);
    }
    return 0;
}
