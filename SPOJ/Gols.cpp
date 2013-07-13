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

int in() {
    int x;
    scanf("%d", &x);
    return x;
}

const int INF = 100010101;
const int MAXN = 1000009;

int T, E, P, J, acc, now, v[MAXN];
char name[25], best[25];

int rmq_both(void) {
    int i, ans = 0;

    deque<int> Q1, Q2;

    for (i = 0; i < J; i++) {
        while (!Q1.empty() && v[i] >= v[Q1.back()]) {
            Q1.pop_back();
        }
        Q1.push_back(i);

        while (!Q2.empty() && v[i] <= v[Q2.back()]) {
            Q2.pop_back();
        }
        Q2.push_back(i);
    }

    for (i = J; i < P; i++) {
        ans += v[Q1.front()];
        ans += v[Q2.front()];

        while (!Q1.empty() && v[i] >= v[Q1.back()]) {
            Q1.pop_back();
        }
        while (!Q1.empty() && Q1.front() <= i-J) {
            Q1.pop_front();
        }
        Q1.push_back(i);

        while (!Q2.empty() && v[i] <= v[Q2.back()]) {
            Q2.pop_back();
        }
        while (!Q2.empty() && Q2.front() <= i-J) {
            Q2.pop_front();
        }
        Q2.push_back(i);
    }

    ans += v[Q1.front()];
    ans += v[Q2.front()];

    return ans;
}

int main(void) {
    T = in();

    int i;

    for ( ; T--; ) {
        E = in(), P = in(), J = in();

        acc = INT_MIN;

        for ( ; E--; ) {
            scanf("%s", name);

            now = 0;

            for (i = 0; i < P; i++) {
                v[i] = in();
            }

            now += rmq_both();

            if (now > acc || now == acc && string(name) < string(best)) {
                acc = now;
                strcpy(best, name);
            }
        }

        printf("%s %d\n", best, acc);
    }
    return 0;
}
