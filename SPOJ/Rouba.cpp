#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <memory>
#include <iomanip>
#include <numeric>
#include <functional>
#include <new>
#include <utility>
#include <valarray>
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

int N, J, v[10010], p[10010][2], discard[15];

int main(void) {
    freopen("i.in", "r", stdin);
    while(2 == scanf("%d%d", &N, &J) && (N + J != 0)) {
        REP(i, N) scanf("%d", &v[i]);
        REP(i, N+1) {
            p[i][0] = 0;
            p[i][1] = -1;
        }
        memset(discard, 0, sizeof(discard));
        int start = 0, now = 0, mx = 0, card;
        while(start < N) {
            if(now == J) now = 0;
            int card = v[start], ok = 0;
            if(discard[card] > 0) {
                p[now][0] += 2;
                p[now][1] = card;
                discard[card] -= 1;
                start++;
                ok = 1;
                mx = max(mx, (int) p[now][0]);
            }
            if(ok) continue;
            REP(i, J) if(p[i][1] == card && p[i][0] > 0 && now != i) {
                p[now][0] += p[i][0] + 1;
                p[now][1] = card;
                p[i][0] = 0;
                p[i][1] = -1;
                start++;
                ok = 1;
                mx = max(mx, (int) p[now][0]);
                break;
            }
            if(ok) continue;
            if(p[now][1] == card) {
                p[now][0] += 1;
                start++;
                ok = 1;
                mx = max(mx, (int) p[now][0]);
            }
            if(ok) continue;
            discard[card] += 1;
            now++;
            start++;
        }
        printf("%d ", mx);
        REP(i, J) {
            if(p[i][0] == mx) {
                printf("%d ", i + 1);
            }
        }
        printf("\n");
    }
    return 0;
}
