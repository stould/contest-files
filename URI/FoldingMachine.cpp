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

int N, M;


vector<int> func(vector<int>& v, int pos) {
    vector<int> ans;

    int i;

    for (i = (int) v.size() - 1; i > 2 * pos && i >= 0; i--) ans.push_back(v[i]);

    for (i = 0; i < pos && i < (int) v.size(); i++) ans.push_back(v[i]);

    int buf, cnt = 0;

    for (i = pos, buf = pos - 1; i < (int) v.size() && buf >= 0 && cnt < pos; i++, cnt++, buf--) {
        ans[buf] += v[i];
    }

    return ans;
}

int main(void) {
    int i;

    for ( ; scanf("%d", &N) == 1; ) {
        vector<int> s(N);

        for (i = 0; i < N; i++) scanf("%d", &s[i]);

        scanf("%d", &M);

        vector<int> g(M);

        for (i = 0; i < M; i++) scanf("%d", &g[i]);

        set<vector<int> > vis;

        vector<int> vr = s; reverse(vr.begin(), vr.end());

        queue<vector<int> > qA; qA.push(s);
        queue<vector<int> > qB; qB.push(vr);

        bool ok = 0;

        for ( ; !qA.empty() || !qB.empty(); ) {
            if (!qA.empty()) {
                vector<int> currA = qA.front(); qA.pop();

                if (currA == g) {
                    ok = 1;
                    break;
                }

                for (i = 1; i < (int) currA.size(); i++) {
                    vector<int> fL = func(currA, i);

                    if (!vis.count(fL) && fL.size() >= M) {
                        vis.insert(fL); qA.push(fL);
                    }
                }
            }

            if (!qB.empty()) {
                vector<int> currB = qB.front(); qB.pop();

                vector<int> rcur = currB;
                reverse(rcur.begin(), rcur.end());

                if (currB == g) {
                    ok = 1;
                    break;
                }


                for (i = 1; i < (int) currB.size(); i++) {
                    vector<int> fR = func(currB, i);

                    if (!vis.count(fR) && fR.size() >= M) {
                        vis.insert(fR); qB.push(fR);
                    }
                }
            }
        }

        printf("%c\n", ok ? 'S' : 'N');
    }
    return 0;
}
