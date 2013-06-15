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

using namespace std;

typedef long long ll;
typedef unsigned uint;

int T, N;
char buff[40];
string str[15];

int main(void) {
    scanf("%d", &T);

    int i, j, next, x;

    for (x = 1; x <= T; x++) {
        scanf("%d", &N);

        map <string, set<string> > partner;

        for (i = 0; i < N; i++) {
            scanf("%s", buff); str[i] = buff;

            scanf("%d", &next);

            for (j = 0; j < next; j++) {
                scanf("%s", buff);
                partner[str[i]].insert(buff);
            }
        }

        if (N == 1) {
            printf("Teste #%d: %d\n", x, 1);
            continue;
        }

        int ans = 0;

        sort(str, str + N);

        do {
            int ok = 1;

            for (i = 0; i < N && ok != 0; i++) {
                if (i == 0) {
                    if (partner[str[i]].count(str[i+1])) ok = 0;
                } else if (i == N - 1) {
                    if (partner[str[i]].count(str[i-1])) ok = 0;
                } else {
                    if (partner[str[i]].count(str[i+1]) || partner[str[i]].count(str[i-1])) ok = 0;
                }
            }

            if (ok) ans += 1;

        } while (next_permutation(str, str + N));

        printf("Teste #%d: %d\n", x, ans);
    }
    return 0;
}
