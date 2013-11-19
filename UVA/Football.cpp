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

int A, B;
int N, G;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - a.second) < abs(b.first - b.second);
}

int main(void) {
    for ( ; scanf("%d%d", &N, &G) == 2; ) {

        int i, ans = 0;

        vector<pair<int, int> > p;

        for (i = 0; i < N; i++) {
            A = in();
            B = in();

            if (A > B) {
                ans += 3;
            } else if (A == B) {
                if (G > 0) {
                    ans += 3;
                    G -= 1;
                } else {
                    ans += 1;
                }
            } else {
                p.push_back(make_pair(A, B));
            }
        }

        sort(p.begin(), p.end(), cmp);

        for (i = 0; i < (int) p.size(); i++) {
            int diff = p[i].second - p[i].first;

            if (G >= diff + 1) {
                ans += 3;
                G -= diff + 1;
            } else if (G == diff) {
                ans += 1;
                G -= diff;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}

