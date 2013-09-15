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

int A, B, C, N;
char buff[15], best_name[15], worst_name[15];

int main(void) {
    int i;

    for ( ; scanf("%d", &N) == 1 && N > 0; ) {
        int best = INT_MIN, worst = INT_MAX;

        for (i = 0; i < N; i++) {
            scanf("%s%d%d%d", buff, &A, &B, &C);

            int money = A * 5 + B * 10 + C * 20;

            if (money > best) {
                best = money;
                strcpy(best_name, buff);
            }
            if (money < worst) {
                worst = money;
                strcpy(worst_name, buff);
            }
        }

        if (best == worst) {
            printf("All have the same amount.\n");
        } else {
            printf("%s has most, %s has least money.\n", best_name, worst_name);
        }
    }
    return 0;
}
