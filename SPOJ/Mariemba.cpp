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

int i, n, x, seq[10];

int main(void) {
    scanf("%d", &n);
    REP(x, n) {
        int count = 0, nim = 0, even = 0;
        REP(i, 6) {
            scanf("%d", &seq[i]);
            if(seq[i] > 1) count += 1;
            if(seq[i] == 1) even += 1;
            nim ^= seq[i];
        }
        printf("Instancia %d\n", x + 1);
        if(count > 0) {
            if(nim != 0) printf("sim\n\n");
            else printf("nao\n\n");
        } else {
            if(even % 2 == 0) printf("sim\n\n");
            else printf("nao\n\n");
        }
    }
    return 0;
}

