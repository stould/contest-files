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

int in(void) { int x; scanf("%d", &x); return x; }

int N, T1, T2, T3, ans;

int func(int start){
    int ans = 3 * N, now = start;

    while (now != T1){
        ans++;
        now = (now - 1 + N) % N;
    }

    while (now != T2){
        ans++;
        now = (now + 1 + N) % N;
    }

    while (now != T3){
        ans++;
        now = (now - 1 + N) % N;
    }
    return ans;
}

int main(void) {
    int i;
    for ( ; scanf("%d%d%d%d", &N, &T1, &T2, &T3) && (N + T1 + T2 + T3 != 0); ) {
        ans = INT_MIN;

        for (i = 0; i < N; i++) {
            ans = max(ans, func(i));
        }

        printf("%d\n", ans);
    }
    return 0;
}

