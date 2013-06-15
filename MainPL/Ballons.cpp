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

const int MAXN = 200007;
int N, I[MAXN], R[MAXN];
double air[MAXN];

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d", &N);

    int i, j, k;

    for (i = 0; i < N; i++) scanf("%d%d", &I[i], &R[i]);

    air[0] = R[0];

    for (i = 1; i < N; i++) {
        double low = 0, high = R[i], mid;

        for (j = 0; j < 20 ; j++) {
            mid = (low + high) / 2.0;

            bool done = false;

            for (k = 0; k < i; k++) {
                if (hypot(I[k] - I[i], air[k] - mid) - mid <= air[k]) {
                    printf("%d %d\n", i, k);
                    done = true;
                }
            }

            if (done) {
                high = mid;
            } else {
                low = mid;
            }
        }
        air[i] = mid;
    }

    for (i = 0; i < N; i++) printf("%.3lf\n", air[i]);
    return 0;
}
