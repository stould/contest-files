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

int v[7];
set<int> A;
set<double> B;

int main(void) {
    int i;

    for (i = 0; i < 4; i++) {
        v[i] = in();
        if (i > 0) {
            A.insert(v[i] - v[i - 1]);
            B.insert((double) v[i] / (double) v[i - 1]);
        }
    }

    double ch_a = floor(v[3] * ((double) v[1] / (double) v[0])), ch_b = ceil(v[3] * ((double) v[1] / (double) v[0]));

    if (A.size() == 1) {
        printf("%d\n", v[3] + (v[1] - v[0]));
    } else if (B.size() == 1 && ch_a == ch_b) {
        printf("%d\n", (int) (v[3] * ((double) v[1] / (double) v[0])));
    } else {
        printf("42\n");
    }

    return 0;
}

