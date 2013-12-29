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

const int MAXN = 200007;

int T, N;

int x[MAXN];
int tree[10000007];

int get(int index) {
    int ans = 0;

    for ( ; index > 0; ) {
        ans += tree[index];
        index -= (index & -index);
    }

    return ans;
}

void increase(int index, int value) {
    for ( ; index <= N; ) {
        tree[index] += value;
        index += (index & -index);
    }
}

int main(void) {
    T = in();

    int i;

    for ( ; T--; ) {
        N = in();

        int tmp[N];
        map<int, int> mp;

        for (i = 1; i <= N; i++) {
            x[i] = in(); tree[i] = 0;
            tmp[i] = x[i];
            mp[x[i]] = i;
        }

        sort(tmp + 1, tmp + N + 1);

        for (i = 1; i <= N; i++) {
            x[mp[tmp[i]]] = i;
        }

        Int ans = 0LL;

        for (i = 1; i <= N; i++) {
            ans += (Int) get(N) - get(x[i]);
            increase(x[i], 1);
        }

        cout << ans << "\n";
    }
    return 0;
}
