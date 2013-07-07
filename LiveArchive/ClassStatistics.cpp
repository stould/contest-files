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

int K, N, T;
int x[60];

int main(void) {
    int i, l, h, gap;

    T = 1;

    for ( ; scanf("%d", &K) == 1; ) {
        for ( ; K--; ) {
            scanf("%d", &N);

            l = 110, h = -110, gap = -100;

            for (i = 0; i < N; i++) {
                scanf("%d", &x[i]);

                chmin(l, x[i]);
                chmax(h, x[i]);
            }

            sort (x, x + N);

            for (i = 1; i < N; i++) chmax(gap, x[i] - x[i - 1]);

            printf("Class %d\nMax %d, Min %d, Largest gap %d\n", T++, h, l, gap);
        }
    }
    return 0;
}
