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

int N;
int init, curr;
bool ok;

int cnt[3];

bool func(int fill) {
    if (fill == 25) {
        cnt[0] += 1;
        return true;
    } else if (fill == 50 && cnt[0] >= 1) {
        cnt[0] -= 1; cnt[1] += 1; return true;
    } else if (fill == 100) {
        if (cnt[1] >= 1 && cnt[0] >= 1) {
            cnt[0] -= 1; cnt[1] -= 1; cnt[2] += 1; return true;
        } else if (cnt[0] >= 3) {
            cnt[0] -= 3; cnt[2] += 1; return true;
        }
    }

    return false;
}

int main(void) {
    int i;

    for ( ; scanf("%d", &N) == 1; ) {
        init = curr = cnt[0] = cnt[1] = cnt[2] = 0;
        ok = true;

        for (i = 0; i < N; i++) {
            curr = in();

            if (!func(curr)) {
                ok = false;
            }
        }

        printf("%s\n", ok ? "YES" : "NO");
    }

    return 0;
}
