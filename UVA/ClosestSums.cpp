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

const int MAXN = 1009;
int N, M, Q,
v[MAXN];

vector<int> s;

void rec(void) {
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) if(i != j) {
        s.push_back(v[i]+v[j]);
    }
}

int b_s(int q) {
    int low = 0, high = s.size(), mid, comp = INT_MAX, ans;

    while(low <= high) {
        mid = (low + high) / 2;
        if(abs(q - s[mid]) < comp) {
            comp = abs(q - s[mid]);
            ans = s[mid];
        }
        if(s[mid] >= q) high = mid - 1;
        else low = mid + 1;
    }
    return ans;
}

int test = 1;

int main(void) {
    while(scanf("%d", &N) == 1 && N != 0) {
        printf("Case %d:\n", test++);
        REP(i, N) {
            scanf("%d", &v[i]);
        }
        s.clear();
        rec();

        sort(s.begin(), s.end());
        s.resize(unique(s.begin(), s.end()) - s.begin());

        scanf("%d", &M);
        REP(i, M) {
            scanf("%d", &Q);
            printf("Closest sum to %d is %d.\n", Q, b_s(Q));
        }
    }
    return 0;
}
