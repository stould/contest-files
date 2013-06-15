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

int i, N;
vector<pair<int, int> > vp;

int diff(pair<int, int> a, pair<int, int> b) {
    return (b.first*60+b.second) - (a.first*60+a.second);
}

int main(void) {
    scanf("%d", &N);
    vp.resize(N);
    REP(i, N) scanf("%d%d", &vp[i].first, &vp[i].second);
    int ans = 1;
    REP(i, N) {
        int j = i + 1, count = 1;;
        while(j < N && diff(vp[i], vp[j]) == 0) {
            j += 1;
            count += 1;
        }
        ans = max(ans, count);
        i = j - 1;
    }
    printf("%d\n", ans);
    return 0;
}

