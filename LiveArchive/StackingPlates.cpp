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

int N, H, tmp, T = 1;

int main(void) {
    freopen("i.in", "r", stdin);
    while(scanf("%d", &N) == 1) {
        vector<int> v[N], all;
        REP(i, N) {
            scanf("%d", &H);
            v[i].resize(H, 0);
            REP(j, H) {
                scanf("%d", &v[i][j]);
                all.push_back(v[i][j]);
            }
        }
        sort(all.begin(), all.end());
        map<int, int> mnext;
        REP(i, all.size()-1) {
            mnext[all[i]] = all[i+1];
        }
        int ans = 0;
        REP(i, N) {
            REP(j, v[i].size()) {
                int k = j;
                while(k < v[i].size() - 1) {
                    if(mnext[v[i][k]] != v[i][k+1]) {
                        ans += 1;
                    }
                    k += 1;
                }
                j = k;
            }
        }
        printf("Case %d: %d\n", T++, ans + (N + ans - 1));
    }
    return 0;
}
