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

int T;
int xmult[6] = {1, 2, 3, 3, 4, 10};
int ymult[7] = {1, 2, 2, 2, 3, 5, 10};

int main(void) {
    T = in();

    int i, x;

    for (x = 1; x <= T; x++) {
        int buff;
        int b = 0, m = 0;

        for (i = 0; i < 6; i++) {
            buff = in();
            b += (buff * xmult[i]);
        }
        for (i = 0; i < 7; i++) {
            buff = in();
            m += (buff * ymult[i]);
        }

        if (b < m) {
            printf("Batalha %d: O Mal erradicou o Bem\n", x);
        } else if (b > m) {
            printf("Batalha %d: O Bem triunfou contra o Mal\n", x);
        } else {
            printf("Batalha %d: Nenhum vencedor no campo de batalha\n", x);
        }
    }
    return 0;
}

