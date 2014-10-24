/*
ID: jeferso1
LANG: C++
TASK: wormhole
*/

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

const int MAXN = 13;

int N;
pair<int, int> P[MAXN];
int next[MAXN];

int with[MAXN];

bool ok() {
    int i;

    for (i = 1; i <= N; i++) {
        int curr = i;
        int run = 0;

        for (run = 0; run < N; run++) {
            curr = next[with[curr]];
        }
        if (curr != 0) {
            return true;
        }
    }
    return false;
}

int func(void) {
    int i, j;

    for (i = 1; i <= N; i++) {
        if (with[i] == 0) {
            break;
        }
    }
    if (i > N) {                
        if (ok()) {            
            return 1;
        } else {
            return 0;
        }
    } else {
        int ans = 0;

        for (j = i + 1; j <= N; j++) if (with[j] == 0) {
            with[j] = i;
            with[i] = j;

            ans += func();

            with[i] = with[j] = 0;
        }

        return ans;
    }
}

int main(void) {
    freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out", "w", stdout);

    N = in();

    int i, j;

    for (i = 1; i <= N; i++) {
        P[i].first = in();
        P[i].second = in();
    }

    memset(next, 0, sizeof(next));
    memset(with, 0, sizeof(with));

    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) if (i != j) {
            if (P[i].second == P[j].second && P[i].first < P[j].first) {                
                if (next[i] == 0 || P[next[i]].first - P[i].first > P[j].first - P[i].first) {                    
                    next[i] = j;
                }
            }
        }
    }    

    printf("%d\n", func());

    return 0;
}
