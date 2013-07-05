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

typedef long long Int;
typedef unsigned uint;

const int MAXN = 109;
int A, B, N;
char str[MAXN];

int x[MAXN], y[MAXN];
map<char, int> m_x, m_y;

void build(void) {
    m_x['U'] = 0; m_y['U'] = 1;
    m_x['D'] = 0; m_y['D'] =-1;
    m_x['L'] =-1; m_y['L'] = 0;
    m_x['R'] = 1; m_y['R'] = 0;

    int i, xx = 0, yy = 0;

    x[0] = y[0] = 0;



    for (i = 0; i < N; i++) {
        xx += m_x[str[i]];
        yy += m_y[str[i]];

        x[i+1] = xx;
        y[i+1] = yy;
    }
}

int main(void) {
    int i, done = 0;
    scanf("%d%d%s", &A, &B, str);

    N = strlen(str);

    build();

    if (A == 0 && B == 0) {
        printf("Yes\n"); return 0;
    }

    for (i = 1; i <= N; i++) {
        int div_a = x[i] / A, mod_a = x[i] % A;
        int div_b = y[i] / B, mod_b = y[i] % B;

        if (div_a == div_b && mod_a == mod_b) {
            printf("Yes\n"); return 0;
        }
    }

    printf("No\n");

    return 0;
}
//4 2
//UURRDL
