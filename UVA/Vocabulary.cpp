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

const int MAXN = 550;

int V, C;

string vc[MAXN];
string ch[MAXN];

bool func(string x, string y) {
    int i;

    int freqX[30] = {0};
    int freqY[30] = {0};

    for (i = 0; i < (int) x.size(); i++) freqX[x[i]-'a'] += 1;
    for (i = 0; i < (int) y.size(); i++) freqY[y[i]-'a'] += 1;

    for (i = 0; i < 26; i++) {
        if (freqY[i] != 0 && freqX[i] == 0) return false;
        if (freqY[i] != 0 && freqX[i] != 0 && freqX[i] % freqY[i] != 0) return false;
    }

    return true;
}

int main(void) {
    int i, j;

    for ( ; scanf("%d%d", &V, &C) == 2; ) {
        for (i = 0; i < V; i++) {
            cin >> vc[i]; sort(vc[i].begin(), vc[i].end());
        }

        bool used[V]; memset(used, false, sizeof(used));

        int ans = 0;

        for (i = 0; i < C; i++) {
            cin >> ch[i]; sort(ch[i].begin(), ch[i].end());
            for (j = 0; j < V; j++) if (!used[j]) {
                if (func(vc[j], ch[i])) {
                    ans += 1;
                    used[j] = true;
                    break;
                }
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
