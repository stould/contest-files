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

char str[1510];
int N, K, cnt[30];

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%s", str); N = strlen(str);

    int i, j;

    for (i = 0; i < 26; i++) {
        scanf("%1d", &cnt[i]);
    }

    K = in();

    unsigned long long int base = 71ULL;

    set<unsigned long long int> s;

    for (i = 0; i < N; i++) {
        unsigned long long int curr = 0ULL;

        int bad = 0;

        for (j = i; j < N; j++) {
            curr = curr * base + (str[j] - 'a' + 1);

            if (!cnt[str[j] - 'a']) bad += 1;

            if (bad > K) {
                break;
            }
            s.insert(curr);
        }
    }

    printf("%d\n", (int) s.size());

    return 0;
}
