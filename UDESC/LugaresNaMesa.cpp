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

const int MAXN = 100007;

int N;
string str[MAXN], str2[MAXN];

int v[MAXN];

int main(void) {
    freopen("i.in", "r", stdin);
    int i;

    for ( ; scanf("%d", &N) == 1 && N != 0; ) {
        int id = 1;

        map<string, int> mp;

        for (i = 1; i <= N; i++) {
            cin >> str[i]; mp[str[i]] = id++;
        }

        int sp = 0;

        for (i = 1; i <= N; i++) {
            cin >> str2[i]; v[i] = mp[str2[i]];
        }

        for (i = 1; i <= N; i++) {
            while (v[i] != i) {
                sp += 1;
                swap(v[v[i]], v[i]);
            }
        }


        printf("%d\n", sp);
    }
    return 0;
}
