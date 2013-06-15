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

int i, j, n, x, a, b;

int main(void) {
    scanf("%d%d", &n, &x);
    set<int> prob;
    REP(i, n) {
        scanf("%d%d", &a, &b);
        set<int> s;
        s.insert(a);
        s.insert(b);
        s.insert(7-a);
        s.insert(7-b);
        int check = 0;
        if(i == 0) {
            s.insert(x);
            s.insert(7-x);
        } else {
            if(s.count(x)) check = 1;
        }
        if(i != 0 && check) {
            puts("NO");
            return 0;
        }
        x = 7 - x;
    }
    puts("YES");
    return 0;
}

