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

int T, N, P, primes[10010] = {0};
char h[125000001];
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

int ans = 0;
map<int, int> mp;

void rec(int sum, ll mult) {
    if(sum > N || mult == 0LL || mp[mult] == 1) return;
    if(sum <= N) {
        mp[(int) mult] = 1;
        ans += 1;
    }
    for(int i = 0; i < p.size(); i++) {
        for(int pi = p[i]; pi + sum <= N; pi *= p[i]) {
            rec(sum + pi, (ll) ((ll)mult * (ll) pi) % (ll) P);
        }
    }
}


int main(void) {
    scanf("%d", &T);
    build(70);
    for( ; T-- ; ) {
        scanf("%d%d", &N, &P);
        ans = 0;
        mp.clear();
        rec(0, 1LL);
        printf("%d\n", ans);
    }
    return 0;
}
