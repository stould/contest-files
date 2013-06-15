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
#include <numeric>
#include <valarray>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <climits>

using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REV(i, a, n) for(int i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

const int MAXN = 1010;
int N, mean, snk, src, mine = 0, more = 0, v[MAXN];

int main(void) {
    //freopen("i.in", "r", stdin);
    scanf("%d", &N);
    REP(i, N) {
        scanf("%d", &v[i]);
    }

    mean = (int) accumulate(v, v + N, 0) / N;

    REP(i, N) {
        if(v[i] < mean) {
            snk = i; mine += 1;
        }
        if(v[i] > mean) {
            src = i; more += 1;
        }
    }

    if(mine == 0 && more == 0) {
        puts("Exemplary pages.");
    } else if(mine == 1 && more == 1 && abs(v[src] - mean) + v[snk] == mean) {
        printf("%d ml. from cup #%d to cup #%d.", abs(mean-v[src]), snk+1, src+1);
    } else {
        puts("Unrecoverable configuration.");
    }
    return 0;
}
