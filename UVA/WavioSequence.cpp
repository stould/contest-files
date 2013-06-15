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

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 10010;
int N, v[MAXN], in[MAXN], de[MAXN], stk[MAXN];

void funcA(void) {
    int i, top = 0;

    stk[0] = INT_MIN;

    for (i = 0; i < N; i++) {
        if (v[i] > stk[top]) {
            stk[++top] = v[i];
        } else {
            int low = 0, high = top;
            while (low <= high) {
                int mid = (low + high) >> 1;
                if (v[i] > stk[mid]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            stk[low] = v[i];
        }
        in[i] = top;
    }
}

void funcB(void) {
    int i, top = 0;

    stk[0] = INT_MIN;

    for (i = 0; i < N; i++) {
        if (v[i] > stk[top]) {
            stk[++top] = v[i];
        } else {
            int low = 0, high = top;
            while (low <= high) {
                int mid = (low + high) >> 1;
                if (v[i] > stk[mid]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            stk[low] = v[i];
        }
        de[i] = top;
    }
}

int main(void) {
    int i, ans;

    while(scanf("%d", &N) == 1) {
        for (i = 0; i < N; i++) {
            scanf("%d", &v[i]);
        }

        funcA();
        reverse(v, v + N);
        funcB();
        reverse(de, de + N);

        ans = -1;

        for (i = 0; i < N; i++) {
            ans = max(ans, min(in[i], de[i]));
        }

        printf("%d\n", 2 * ans - 1);
    }
    return 0;
}
