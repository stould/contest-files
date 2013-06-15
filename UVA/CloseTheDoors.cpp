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

const int MAXN = 25000009;
int N, v[MAXN];

int main(void) {
    int i;

    for (i = 1; i < MAXN; i++) v[i] = 0;

    for (i = 1; i * i < MAXN; i++) v[i] = 1;

    while(scanf("%d", &N) == 1 && N != 0) {
        vector<int> ans;
        for (i = 1; i <= N; i++) {
            if(v[i] == 1) {
                ans.push_back(i);
            }
        }
        for (i = 0; i < ans.size(); i++) {
            if(i == ans.size() - 1) {
                printf("%d\n", ans[i]);
            } else {
                printf("%d ", ans[i]);
            }
        }
    }
    return 0;
}
