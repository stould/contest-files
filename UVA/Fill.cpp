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

int T, A, B, C, D;

struct state {
    vector<int> v;
    int pr;

    state() {
        v.resize(3);
    }
    state(int _a, int _b, int _c, int _pr) {
        v.resize(3);
        v[0] = _b;
        v[1] = _b;
        v[2] = _c;
        pr = _pr;
    }

    bool operator<(const state& s) const {
        return pr > s.pr;
    }
};

set<vector<int> > memo;

int main(void) {
    //freopen("i.in", "r", stdin);
    scanf("%d", &T);

    int bp[4];

    int i, j, k;

    for ( ; T--; ) {
        scanf("%d%d%d%d", &bp[0], &bp[1], &bp[2], &bp[3]);

        memo.clear();

        state base = state(0, 0, bp[2], 0);
        priority_queue<state> q;

        memo.insert(base.v);
        q.push(base);

        int ans = INT_MAX / 3, p = -1;

        for ( ; !q.empty(); ) {
            state curr = q.top(); q.pop();

            if (curr.v[0] >= 0 && curr.v[0] <= bp[3] && ((p < curr.v[0]) || (p == curr.v[0] && curr.pr < ans))) {
                //cout << curr.v[0] << " " << curr.v[1] << " " << curr.v[2] << " " << curr.pr << "\n";
                ans = curr.pr;
                p = curr.v[0];
            }
            if (curr.v[1] >= 0 && curr.v[1] <= bp[3] && ((p < curr.v[1]) || (p == curr.v[1] && curr.pr < ans))) {
                //cout << curr.v[0] << " " << curr.v[1] << " " << curr.v[2] << " " << curr.pr << "\n";
                ans = curr.pr;
                p = curr.v[1];
            }
            if (curr.v[2] >= 0 && curr.v[2] <= bp[3] && ((p < curr.v[2]) || (p == curr.v[2] && curr.pr < ans))) {
                //cout << curr.v[0] << " " << curr.v[1] << " " << curr.v[2] << " " << curr.pr << "\n";
                ans = curr.pr;
                p = curr.v[2];
            }

            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    if (i != j) {
                        int pa = max(0, min(bp[i] - curr.v[i], curr.v[j]));
                        int pb = max(0, min(bp[j] - curr.v[j], curr.v[i]));

                        if (pa > 0) {
                            state tmp;
                            for (k = 0; k < 3; k++) {
                                if (k == i) {
                                    tmp.v[k] = curr.v[k] + pa;
                                } else if (k == j) {
                                    tmp.v[k] = curr.v[k] - pa;
                                } else {
                                    tmp.v[k] = curr.v[k];
                                }
                            }
                            tmp.pr = curr.pr + pa;
                            if (memo.count(tmp.v) == 0) {
                                memo.insert(tmp.v);
                                q.push(tmp);
                            }
                        }
                        if (pb > 0) {
                            state tmp;
                            for (k = 0; k < 3; k++) {
                                if (i == k) {
                                    tmp.v[k] = curr.v[k] - pb;
                                } else if (j == k) {
                                    tmp.v[k] = curr.v[k] + pb;
                                } else {
                                    tmp.v[k] = curr.v[k];
                                }
                            }
                            tmp.pr = curr.pr + pb;
                            if (memo.count(tmp.v) == 0) {
                                memo.insert(tmp.v);
                                q.push(tmp);
                            }
                        }
                    }
                }
            }
        }

        printf("%d %d\n", ans, p);
    }
    return 0;
}
