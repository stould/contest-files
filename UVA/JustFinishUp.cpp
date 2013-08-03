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

const int MAXN = 100001;

int T, N;
int P[MAXN], Q[MAXN];

int func(int x) {
    int i, R = 0, fuel = 0;

    for (i = x; R < N; i++, R++) {
        i %= N;

        fuel += P[i];

        if (fuel < Q[i]) {
            return 0;
        }

        fuel -= Q[i];
    }

    return 1;
}

int main(void) {
    T = in();

    int i, x;

    for (x = 1; x <= T; x++) {
        N = in();

        int f = 0;

        for (i = 0; i < N; i++) {
            P[i] = in();
        }
        for (i = 0; i < N; i++) {
            Q[i] = in();
            f += P[i] - Q[i];
        }

        printf("Case %d: ", x);

        if (f < 0) {
            puts("Not possible");
        } else {
            for (i = 0; i < N; i++) {
                if (func(i)) {
                    printf("Possible from station %d\n", i + 1);
                    break;
                }
            }
        }
    }
    return 0;
}
