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

const int MAXN = 26909;

int N;
int used[MAXN];

vector<int> buff;

int main(void) {
    int i, j;

    for (i = 0; i < MAXN; i++) used[i] = 1;

    for (i = 2; i < sqrt(MAXN); i++) if (used[i]) {
        int sum = 0;

        //buff.push_back(i);

        for (j = i + 1; j < MAXN; j++) if (used[j]) {
            sum += 1;

            if (sum % i == 0) {
                used[j] = 0;
            }
        }
    }

    for (i = 2; i < MAXN; i++) if (used[i]) buff.push_back(i);

    for ( ; scanf("%d", &N) == 1 && N != 0; ) {
        printf("%d\n", buff[N-1]);
    }

    return 0;
}
