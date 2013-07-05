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
    if (!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

const int MAXN = 50;
int N, M, G, A, B;
int played[MAXN], against[MAXN], mp[MAXN];
char ot;

void clear (void) {
    int i;

    for (i = 0; i < MAXN; i++) {
        played[i] = against[i] = mp[i] = 0;
    }
}

int main(void) {
    freopen("i.in", "r", stdin);
 //   freopen("o.ot", "w", stdout);

    int i;

    for ( ; scanf("%d%d%d", &N, &M, &G) == 3 && (N + M + G != 0); ) {
        clear ();
        for (i = 0; i < G; i++) {
            scanf("%d %c%d", &A, &ot, &B);

            if (ot == '=') {
                mp[A] += 1;
                mp[B] += 1;
            } else if (ot == '<') {
                mp[B] += 2;
            } else {
                mp[A] += 2;
            }

            played[A] += 1;
            played[B] += 1;

            if (A == 0) against[B] += 1;
            if (B == 0) against[A] += 1;
        }

        int pt = ((N - 1) * M - played[0]) * 2, ok = 1;

        for (i = 1; i < N; i++) {
            mp[i] += ((N - 1) * M - played[i] - (M - against[i]));
        }

        for (i = 1; i < N; i++) {
            if (mp[i] > mp[0] + pt) {
                    ok = 0;
            }
        }

        if (ok) {
            puts("Y");
        } else {
            puts("N");
        }
    }
    return 0;
}
