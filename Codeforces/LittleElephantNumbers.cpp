#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <functional>
#include <valarray>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <climits>

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

ll n;
int ch[11] = {0};

int func(ll x) {
    while(x > 0) {
        if(ch[x % 10]) return 1;
        x /= 10;
    }
    return 0;
}

int main(void) {
    scanf("%I64d", &n);
    ll _n = n;
    while(_n > 0) {
        ch[_n % 10] += 1; _n /= 10;
    }
    ll ans = 0LL;
    for(ll i = 1LL; i * i <= n; i += 1LL) {
        if(n % i == 0) {
            ans += func(i);
            if(i * i != n) ans += func(n/i);
        }
    }
    printf("%I64d\n", ans);
    return 0;
}

