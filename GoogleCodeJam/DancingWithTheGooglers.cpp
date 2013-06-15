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

const int MAXN = 110;
int T, N, S, P, ans, v[MAXN], test = 1;

bool func(int stp[3]) {
    return stp[0] >= 0 && stp[0] <= 10 && stp[1] >= 0 && stp[1] <= 10 && stp[2] >= 0 && stp[2] <= 10 && max(stp[0], max(stp[1], stp[2])) -  min(stp[0], min(stp[1], stp[2])) <= 2;
}

int main(void) {
    freopen("i.in", "r", stdin);
    freopen("o.ot", "w", stdout);
    scanf("%d", &T);

    for( ; T--; ) {
        scanf("%d%d%d", &N, &S, &P);
        REP(i, N) {
            scanf("%d", &v[i]);
        }

        ans = 0;

        REP(i, N) {
            bool valid = false, valid_as_diff = false;
            for(int x = P; x <= 10; x++) {
                int stp[3] = {x, 0, 0};
                for(int a = -2; a <= 0; a++) {
                    for(int b = -2; b <= 2; b++) {
                        stp[1] = (stp[0] + a);
                        stp[2] = (stp[1] + b);

                        if(!func(stp)) continue;

                        if(stp[0] + stp[1] + stp[2] == v[i]) {
                            if(max(stp[0], max(stp[1], stp[2])) -  min(stp[0], min(stp[1], stp[2])) == 2) {
                                valid_as_diff = true;
                            } else {
                                valid = true;
                            }
                        }
                    }
                }
            }
            end:;
            if(valid) {
                ans += 1;
            } else if(valid_as_diff && S > 0) {
                S -= 1;
                ans += 1;
            }
        }
        printf("Case #%d: %d\n", test++, ans);
    }
    return 0;
}
