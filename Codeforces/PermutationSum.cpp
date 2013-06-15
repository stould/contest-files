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

const int MOD = 1000000007;
int N, fact[20];

ll func(int N) {
    fact[0] = fact[1] = 1;
    for(int i = 1; i <= 16; i++) fact[i] = (ll) fact[i - 1] * (ll) i;

    ll ans = 0LL;

    vector<int> a(N), b(N);

    REP(i, N) a[i] = b[i] = i + 1;

    do {
        do {
            set<int> mem;
            REP(i, N) {
                int curr = ((a[i] - 1 + b[i] - 1) % N) + 1;
                mem.insert(curr);
            }
            if(mem.size() == N) ans += 1LL;
        } while(next_permutation(b.begin(), b.end()));
    } while(next_permutation(a.begin(), a.end()));
    return ans;
}

//int ans[17] = {0, 1, 0, 18, 1800, 0, 670320}

int main(void) {
    return 0;
}
