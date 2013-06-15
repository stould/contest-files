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

int i, j, g[3], p[3];

bool func(int x) {
    int big = 0;
    vector<int> novo;
    novo.push_back(p[0]);
    novo.push_back(p[1]);
    novo.push_back(x);
    sort(novo.begin(), novo.end());
    vector<bool> usedA(3, false);
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(novo[i] < g[j] && usedA[j] == false) {
                big += 1;
                usedA[j] = true;
                break;
            }
        }
    }
    return big == 1;
}

int main(void) {
    for( ;scanf("%d%d%d%d%d", &g[0], &g[1], &g[2], &p[0], &p[1]) && !(g[0]+g[1]+g[2]+p[0]+p[1] == 0); ) {
        int biggie = 0;
        vector<bool> used(3, false);
        sort(g, g + 3);
        bool ok = 0;
        for(i = 1; i <= 52; i++) {
            if(i != g[0] && i != g[1] && i != g[2] && i != p[0] && i != p[1] && func(i)) {
                printf("%d\n", i);
                ok = 1;
                break;
            }
        }
        if(!ok) puts("-1");
    }
    return 0;
}

