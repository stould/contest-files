#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <functional>
#include <valarray>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <climits>

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

int i, j, n, x, y;

int main(void) {
    scanf("%d", &n);
    REP(i, n) {
        scanf("%d%d", &x, &y); y -= 1;
        vector<int> u(x); REP(j, x) u[j] = j + 1;
        int start = 0;
        while(1) {
            start = (start + y) % x;
            u.erase(u.begin() + start);
            x -= 1;
            if(u.size() == 1) break;
        }
        printf("Case %d: %d\n", i + 1, u[0]);
    }
    return 0;
}

