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

int T, N, A, B, C, v[25];

int func(int x, int y) {
    return A*(x-y)*(x-y) + B*abs(x-y) + C;
}

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d", &T);
    for( ; T--; ) {
        scanf("%d%d%d%d", &N, &A, &B, &C);
        REP(i, N) scanf("%d", &v[i]);

        sort(v, v + N);
        double ans = 100000000;
        do {
            double value = 0.0;
            REP(i, N - 1) {
                value += (double) func(i, i + 1)/(double)v[i];
            }
            if(value < ans) ans = value;
        } while(next_permutation(v, v + N));
        printf("%.3lf\n", ans);
    }
    return 0;
}
