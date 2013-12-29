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

const int MAXN = 64809;

int H, M, S, N;
char T;

struct event {
    int stamp;
    char type;

    event(){}

    event(int s, char c) {
        stamp = s;
        type = c;
    }

    bool operator<(const event& e) const {
        return stamp < e.stamp;
    }
};

event e[MAXN];

int main(void) {
    int i;

    for ( ; scanf("%d", &N) == 1 && N != 0; ) {
        int ne = N / 2;

        for (i = 0; i < N; i++) {
            scanf(" %d:%d:%d %c", &H, &M, &S, &T);
            e[i] = event(H * 3600 + M * 60 + S, T);

            if (T == 'E') ne -= 1;
        }

        sort(e, e + N);

        int curr = 0, ans = 0;

        for (i = 0; i < N; i++) {
            if (e[i].type == 'E') {
                curr += 1;
            } else if (e[i].type == 'X') {
                curr -= 1;
            } else {
                if (ne) {
                    curr += 1; ne -= 1;
                } else {
                    curr -= 1;
                }
            }
            ans = max(ans, curr);
        }

        printf("%d\n", ans);
    }
    return 0;
}
