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
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

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

int i, j, n, p, a, indi, indj, m, left, right;

int main(void) {
    while(scanf("%d%d", &n, &p) && !(n == 0 && p == 0)) {
        vector<int> pilha[p];
        REP(i, p) {
            scanf("%d", &a);
            pilha[i].resize(a);
            REP(j, a) {
                scanf("%d", &pilha[i][j]);
                if(pilha[i][j] == 1) {
                    indi = i; indj = j + 1;
                }
            }
        }
        ::left = ::right = pilha[indi].size() - indj;
        for(i = indi - 1; i >= 0; i--) {
            if(pilha[i].size() >= indj) {
                ::left += pilha[i].size() - indj + 1;
            } else {
                break;
            }
        }
        for(i = indi + 1; i < p; i++) {
            if(pilha[i].size() >= indj) {
                ::right += pilha[i].size() - indj + 1;
            } else {
                break;
            }
        }
        printf("%d\n", ::left < ::right ? ::left : ::right);
    }
    return 0;
}

