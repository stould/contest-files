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

const int MAXN = 100007;

int N;
int c[MAXN], mark[MAXN];

struct triplet {
    int a, b, c;

    triplet(void) {}

    triplet(int a, int b, int c):
        a(a), b(b), c(c)
    {}
};

int main(void) {
    N = in();

    int i, j, k;

    for (i = 0; i < N; i++) {
        c[i] = in();
        mark[i] = 0;
    }

    sort(c, c + N);

    vector<triplet> vt;

    for (i = 0; i < N; i++) if (!mark[i]) {
        for (j = i + 1; j < N; j++) if (!mark[j] && c[j] > c[i]) {
            for (k = j + 1; k < N; k++) if (!mark[k] && c[k] > c[j]) {
                if (c[k] % c[j] == 0 && c[j] % c[i] == 0) {
                    vt.push_back(triplet(c[i], c[j], c[k]));
                    mark[i] = mark[j] = mark[k] = 1;
                    goto end;
                }
            }
        }
        end:;
    }

    if (3 * (int) vt.size() == N) {
        for (i = 0; i < (int) vt.size(); i++) {
            printf("%d %d %d\n", vt[i].a, vt[i].b, vt[i].c);
        }
    } else {
        puts("-1");
    }


    return 0;
}
