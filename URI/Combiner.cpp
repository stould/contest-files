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

int N, an, bn;
string a, b;

int main(void) {
    //ios::sync_with_stdio(false);
    cin >> N;
    for ( ; N > 0; ) {
        cin >> a >> b;
        an = bn = 0;
        while(an < a.size() || bn < b.size()) {
            if(an < a.size()) putchar(a[an++]);
            if(bn < b.size()) putchar(b[bn++]);
        }
        cout << "\n";
        N--;
    }
    return 0;
}

