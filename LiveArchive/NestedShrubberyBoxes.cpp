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

const int MAXN = 507;

int N;
int L[MAXN], W[MAXN], H[MAXN];

int dp[MAXN][MAXN];

int fit (int x, int y) {
    int buff[3] = {L[x], W[x], H[x]};

    sort (buff, buff + 3);

    do {
        if (buff[0] < L[y] && buff[1] < W[y] && buff[2] < H[y]) return 1;
    } while (next_permutation(buff, buff + 3));

    return 0;
}

int func(int index, int last) {
    if (index == N + 1) return 0;

    int& ans = dp[index][last];

    if (ans != -1) return ans;

    ans = func(index + 1, last);

    if (fit(last, index)) {
        ans = max(ans, 1 + func(index + 1, index));
    }

    return ans;
}

int main(void) {
    int i, j;

    L[0] = W[0] = H[0] = 0;

    for ( ; scanf("%d", &N) == 1 && N != -1; ) {
        for (i = 1; i <= N; i++) {
            L[i] = in();
            W[i] = in();
            H[i] = in();
        }

        for (i = 1; i <= N; i++) {
            for (j = i + 1; j <= N; j++) {
                int vol_i = L[i] * W[i] * H[i];
                int vol_j = L[j] * W[j] * H[j];

                if (vol_i > vol_j) {
                    swap(L[i], L[j]);
                    swap(W[i], W[j]);
                    swap(H[i], H[j]);
                }
            }
        }

        memset(dp, -1, sizeof(dp));

        printf("%d\n", func(1, 0));
    }
    return 0;
}
