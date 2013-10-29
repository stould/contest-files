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

const int MAXN = 1010;

struct data {
    int w, s, id;

    data(){}

    data(int w, int s, int id): w(w), s(s), id(id){}
};

data p[MAXN];

bool cmp(data a, data b) {
    if (a.w != b.w) {
        return a.w < b.w;
    } else {
        return a.s > b.s;
    }
}

int N;

int dp[MAXN];
int pr[MAXN];

int main(void) {
    int a, b, i, j;

    N = 0;

    for ( ; scanf("%d%d",&a, &b) == 2; ) {
        p[N++] = data(a, b, ++N);
    }

    sort(p, p + N, cmp);

    int best = 0, index;

    for (i = N - 1; i >= 0; i--) {
        dp[i] = 1;
        pr[i] =-1;

        for (j = i + 1; j < N; j++) {
            if (p[i].w < p[j].w && p[i].s > p[j].s && 1 + dp[j] > dp[i]) {
                dp[i] = dp[j] + 1;
                pr[i] = j;
            }
        }

        if (dp[i] > best) {
            best = dp[i];
            index = i;
        }
    }

    printf("%d\n", best);

    for (i = index; i != -1; i = pr[i]) {
        printf("%d\n", p[i].id);
    }

    return 0;
}
