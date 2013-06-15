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

const int MAXN = 1000000;
int N, t1, t2, digit[MAXN+10], prime[MAXN+10], ok[MAXN+10], sum[MAXN + 10];

void setup() {
    REP(i, MAXN+1) {
        digit[i] = ok[i] = sum[i] = 0;
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;

    FOR(i, 2, (int) sqrt(MAXN+1)) {
        if(prime[i] == 1) {
            for(int j = i*i; j <= MAXN; j += i) {
                prime[j] = 0;
            }
        }
    }

    REP(i, MAXN) {
        digit[i] += digit[i/10] + i % 10;
        if(prime[i] && prime[digit[i]]) ok[i] = 1;
        sum[i] = sum[i - 1] + ok[i];
    }
}

int main(void) {
    scanf("%d", &N);
    setup();
    REP(i, N) {
        scanf("%d%d", &t1, &t2);
        printf("%d\n", sum[t2] - sum[t1 - 1 < 0 ? t1 : t1 - 1]);
    }
    return 0;
}

