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

const int MAXN = 10009;

int N;
double A[MAXN], B[MAXN];

int main(void) {
    freopen("i.in", "r", stdin);
    N = in();

    int i, j;

    double sum_A = 0.0, sum_B = 0.0;

    bool used[N]; memset(used, false, sizeof(used));

    for (i = 0; i < 2 * N; i++) {
        scanf("%lf", &A[i]); B[i] = A[i];
    }

    for (i = 0; i < 2 * N; i++) {
        for (j = 0; j < 2 * N; j++) if (!used[i] && !used[j] && i != j) {
            double paramA = A[i], fractpartA, intpartA;
            fractpartA = modf(paramA, &intpartA);

            double paramB = A[j], fractpartB, intpartB;
            fractpartB = modf(paramB, &intpartB);

            if (fractpartA != 0.0 && fractpartB != 0.0) {
                if (fractpartA <= 0.5 && fractpartB > 0.5)  {
                    A[i] = floor(A[i]);
                    A[j] = ceil(A[j]);
                    used[i] = used[j] = true;
                } else if (fractpartA > 0.5 && fractpartB <= 0.5)  {
                    A[i] = ceil(A[i]);
                    A[j] = floor(A[j]);
                    used[i] = used[j] = true;
                }
            }
        }
    }

    int u = 0;

    for (i = 0; i < 2 * N; i++) {
        if (used[i]) u += 1;
    }

    vector<pair<double, int> > buf;

    for (i = 0; i < 2 * N; i++) {
        double paramA = A[i], fractpartA, intpartA;
        fractpartA = modf(paramA, &intpartA);

        if (!used[i] && fractpartA != 0.0) {
            buf.push_back(make_pair(max(fractpartA, fabs(1.0 - fractpartA)), i));
        }
    }

    sort(buf.begin(), buf.end());
    reverse(buf.begin(), buf.end());

    for (i = 0; i < buf.size() && u + 1 < 2 * N; i++, u += 2) {
        double paramA = A[buf[i].second], fractpartA, intpartA;
        fractpartA = modf(paramA, &intpartA);

        if (fractpartA <= 0.5) {
            A[buf[i].second] = floor(A[buf[i].second]);
        } else {
            A[buf[i].second] = ceil(A[buf[i].second]);
        }
    }

    for (i = 0; i < 2 * N; i++) {
        sum_A += A[i];
        sum_B += B[i];

        printf("%.3lf %.3lf\n", A[i], B[i]);
    }

    printf("%.3lf\n", fabs(sum_A - sum_B));

    return 0;
}
