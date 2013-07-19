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

int N;
int goal[13], cnt[13];
char buf[210];

int main(void) {
    N = in();

    while (N > 0) {
        goal[N % 10] += 1; N /= 10;
    }

    scanf("%s", buf);

    int i, A = 0, B = 0;

    for (i = 0; i < strlen(buf); i++) {
        if (buf[i] == '2' || buf[i] == '5') {
            A += 1;
        } else if (buf[i] == '6' || buf[i] == '9') {
            B += 1;
        } else {
            cnt[buf[i]-'0'] += 1;
        }
    }

    int ans = 0, ok = 1;

    while (ok) {
        for (i = 0; i < 10; i++) if (goal[i] != 0) {
            if (i == 2 || i == 5) {
                if (A - goal[i] >= 0) {
                    A -= goal[i];
                } else {
                    ok = 0;
                }
            } else if (i == 6 || i == 9) {
                if (B - goal[i] >= 0) {
                    B -= goal[i];
                } else {
                    ok = 0;
                }
            } else {
                if (cnt[i] - goal[i] >= 0) {
                    cnt[i] -= goal[i];
                } else {
                    ok = 0;
                }
            }
        }
        if (ok) ans += 1;
    }

    printf("%d\n", ans);

    return 0;
}
