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

int T, L, R, dp[10010], primes[10010] = {0};
vector<int> p;

void build(int V) {
    primes[0] = primes[1] = 1;

    for(int i = 2; i <= (int) sqrt(V); i++) {
        if(primes[i] == 0) {
            for(int j = i*i; j <= V; j += i) {
                primes[j] = 1;
            }
        }
    }
    for(int i = 2; i <= V; i++) if(primes[i] == 0) {
        p.push_back(i);
    }
}

int factorize(int v) {
    int ans = 1, pos = 0, vv = v;

    while(v > 1) {
        int now = 0;
        while(v % p[pos] == 0) {
            v /= p[pos];
            now += 1;
        }
        if(now != 0) ans *= (now+1);
        pos += 1;
    }
    return dp[vv] = ans;
}

int main(void) {
    scanf("%d", &T);

    memset(dp, -1, sizeof(dp));

    build(10000);

    for( ; T--; ) {
        scanf("%d%d", &L, &R);
        bool ok = false;
        vector<int> ans;
        for(int i = L; i <= R; i++) {
            if(i <= 1) continue;
            if(dp[i] == -1) {
                dp[i] = factorize(i);
            }
            if(primes[dp[i]] == 0) {
                ans.push_back(i);
                ok = true;
            }
        }
        if(!ok) printf("-1");
        else {
            for(int i = 0; i < ans.size(); i++) {
                printf("%d", ans[i]);
                if(i != ans.size()-1) printf(" ");
            }
        }
        puts("");
    }
    return 0;
}
