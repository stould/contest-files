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

int i, n, k;
char str[110];
map<char, int> mp;

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d%s", &k, str); n = strlen(str);
    REP(i, n) {
        mp[str[i]] = 1;
    }
    REP(i, strlen(str)) {
        if(str[i] != '?' && str[n-i-1] != '?' && str[i] != str[n-i-1]) {
            puts("IMPOSSIBLE"); return 0;
        }
        if(str[i] == '?' && str[n-i-1] == '?') {
            for(char c = 'a'; c <= 'z' && c - 'a' <= k; c++) {
                str[i] = str[n-i-1] = c;
                break;
            }
         //   puts("IMPOSSIBLE"); return 0;
        }
        if(str[i] == '?' && str[n-i-1] != '?') str[i] = str[n-i-1];
        if(str[i] != '?' && str[n-i-1] == '?') str[n-i-1] = str[i];
    }
    printf("%s\n", str);
    return 0;
}

