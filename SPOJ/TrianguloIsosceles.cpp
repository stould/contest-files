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

const int MAXN = 1010;
int N, ans;
double x[MAXN], y[MAXN];
pair<double, double> vp[MAXN];

int main(void) {
    freopen("i.in", "r", stdin);
    int i, j, k;
    for ( ; scanf("%d", &N) && N != 0; ) {
        for (i = 0; i < N; i++) scanf("%lf%lf", &vp[i].first, &vp[i].second);

        sort(vp, vp + N);

        for (i = 0; i < N; i++) x[i] = vp[i].first, y[i] = vp[i].second;

        ans = 0;

        for (i = 0; i < N; i++) {
            for (j = i + 1; j < N; j++) {
                for (k = j + 1; k < N; k++) {
                    double A = hypot(x[i] - x[j], y[i] - y[j]);
                    double B = hypot(x[i] - x[k], y[i] - y[k]);
                    double C = hypot(x[j] - x[k], y[j] - y[k]);

                    if (A > B) swap(A, B);
                    if (A > C) swap(A, C);
                    if (B > C) swap(B, C);

                    if (A + B < C) break;

                    if (A == B && B != C && A != C) {
                        ans += 1;
                    } else if (B == C && A != B && A != C) {
                        ans += 1;
                    } else if (A == C && B != A && B != C) {
                        ans += 1;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
