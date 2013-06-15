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

const int MAXN = (int) 10e5 + 10;
int s, b, esq, dir, sit[MAXN], hidari[MAXN], migi[MAXN];

int main(void) {
    while(scanf("%d%d", &s, &b) == 2 && s + b > 0) {
        REP(i, s + 1) {
            sit[i] = 1;
            hidari[i] = i - 1;
            migi[i] = i + 1;
        }
        REP(i, b) {
            scanf("%d%d", &esq, &dir);
            esq--; dir--;
            for(int x = esq; x <= dir; x++) sit[x] = 0;

            int next_hirari = esq, next_migi = dir;

            while(next_hirari >= 0 && sit[next_hirari] == 0) next_hirari = hidari[next_hirari];
            while(next_migi <= s && sit[next_migi] == 0) next_migi = migi[next_migi];


            for(int x = esq; x <= dir; x++) {
                hidari[x] = next_hirari;
                migi[x] = next_migi;
            }

            if(next_hirari == -1) {
                printf("%c ", '*');
            } else {
                printf("%d ", next_hirari + 1);
            }
            if(next_migi == s) {
                printf("%c\n", '*');
            } else {
                printf("%d\n", next_migi + 1);
            }
        }
        printf("-\n");
    }
    return 0;
}
