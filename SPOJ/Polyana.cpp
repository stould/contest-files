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

#define REP(i, n) for((i) = 0; i < n; i++)
#define FOR(i, a, n) for((i) = a; i < n; i++)
#define FORR(i, a, n) for((i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long ll;
typedef long double ld;

int i, m;
char tmp[10], trash[4];

int main(void) {
    freopen("i.in", "r", stdin);
    while(scanf("%d", &m) && m != 0) {
        vector<pair<int, int> > p(m);
        REP(i, m) {
            scanf("%s", tmp);
            p[i].first = tmp[1] - '0' + (10 * (tmp[0] -'0'));
            p[i].second = tmp[6] - '0' + (10 * (tmp[5] -'0'));
        }
        int smallest = 1100000, smallM = 0, smallS = 0, largest = 0, largeM = 0, largeS = 0;
        for(int i = 1; i < m; i++) {
            int ac = p[i].first * 60 + p[i].second;
            int before = p[i - 1].first * 60 + p[i - 1].second;
            if(ac - before < smallest) {
                smallest = ac - before;
                smallM = p[i].first - p[i - 1].first;
                smallS = p[i].second - p[i - 1].second;
            }
            if(ac - before > largest) {
                largest = ac - before;
                largeM = p[i].first - p[i - 1].first;
                largeS = p[i].second - p[i - 1].second;

            }
        }
        if(smallM < 10) {
            printf("0%dmin", abs(smallM));
        } else {
            printf("%dmin", abs(smallM));
        }
        if(smallS < 10) {
            printf("0%ds ", abs(smallS));
        } else {
            printf("%ds ", abs(smallS));
        }

        if(largeM < 10) {
            printf("0%dmin", abs(largeM));
        } else {
            printf("%dmin", abs(largeM));
        }
        if(largeS < 10) {
            printf("0%ds\n", abs(largeS));
        } else {
            printf("%ds\n", abs(largeS));
        }
    }
    return 0;
}

