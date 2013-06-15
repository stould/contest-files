/*
ID: jeferso1
PROG: ariprog
LANG: C++
*/
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

const int MAXN = 25;
int N, M, memo[1250007];
vector<pair<int, int> > vp;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second) return a.second < b.second;
    else return a.first < b.first;
}

int main(void) {

    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);

    int i, j, k;

    scanf("%d%d", &N, &M);

    memset(memo, 0, sizeof(memo));

    for (i = 0; i <= M; i++) for (j = 0; j <= M; j++) memo[i*i+j*j] = 1;

    for (i = 0; i <= 2*(M*M); i++) if(memo[i] != 0) {
        for (j = 1; j <= 5000; j++) {
            bool ok = true;
            int current = i;
            for (k = 0; k < N; k++) {
                if(memo[current] == 0) {
                    ok = false; break;
                }
                current += j;
            }
            if(ok) {
                vp.push_back(make_pair(i, j));
            }
        }
    }

    if(vp.empty()) {
        printf("NONE\n");
    } else {
        sort(vp.begin(), vp.end(), cmp);

        for (i = 0; i < vp.size(); i++) {
            printf("%d %d\n", vp[i].first, vp[i].second);
        }
    }

    return 0;
}
