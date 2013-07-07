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

int N;
int buff[10000007];

int main(void) {
    scanf("%d", &N);

    int i, j, cnt = 0;

    memset(buff, 0, sizeof(buff));

    buff[0] = buff[1] = 1;

    for (i = 2; i <= sqrt(10000000); i++) {
        if (buff[i] == 0) {
            if (cnt == N) break;

            for (j = i * i; j <= 10000000; j += i) {
                buff[j] = 1;
            }
        }
    }

    for (i = 2; i <= 10000000 && cnt != N; i++) {
        if (buff[i] == 0) {
            cnt += 1;
            printf("%d ", i);
        }
    }
    return 0;
}

