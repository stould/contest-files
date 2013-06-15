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

int i, n, k;

bool ok(vector<int>& v) {
    int i;
    set<int> s;
    REP(i, n) s.insert(v[i]);
    return s.size() == 1;
}

int main(void) {
    scanf("%d%d", &n, &k); k -= 1;
    vector<int> v(n);
    REP(i, n) {
        scanf("%d", &v[i]);
    }
    FOR(i, k + 1, n) {
        if(v[i] != v[i - 1]) {
            puts("-1"); return 0;
        }
    }
    i = k - 1;
    while(i >= 0 && (v[k] == v[i])) i -= 1;
    printf("%d\n", i + 1);
    return 0;
}
