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

int N;
string str;

vector<int> build_failure_function(const string &pattern) {
    int m = pattern.size();
    vector<int> F(m+1, 0);
    F[0] = -1;
    for(int i = 0; i < m; i++) {
        F[i+1] = F[i] + 1;
        while(F[i + 1] > 0 && pattern[i] != pattern[F[i+1]-1]) {
            F[i+1] = F[F[i+1]-1] + 1;
        }
    }
    return F;
}

int test = 1;

int main(void) {
    freopen("i.in", "r", stdin);
    while(scanf("%d", &N) == 1 && N != 0) {
        cin >> str;
        printf("Test case #%d\n", test++);
        vector<int> v = build_failure_function(str);
        for(int i = 1; i < v.size(); i++) {
            printf("%d ", v[i]);
        }
        puts("");
        for(int i = 1; i < v.size(); i++) if(v[i] > 0) {
            if(v[i] % (i-v[i]) == 0) {
                printf("%d %d\n", i, i / (i-v[i]));
            }
        }
        printf("\n");
    }
    return 0;
}
