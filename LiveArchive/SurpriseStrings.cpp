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
#include <numeric>
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

char str[100];

int main(void) {
    while(scanf("%s", str) == 1 && strcmp(str, "*") != 0) {
        int surp = 0, N = strlen(str);
        for(int x = 1; x < N - 1; x++) {
            set<string> s;
            int cnt = 0;
            for(int i = 0; i + x < N; i++) {
                s.insert(string(1, str[i]) + string(1, str[i + x])); cnt += 1;
            }
            if(cnt == s.size()) surp += 1;
        }
        if(surp == N - 2 || N == 1) {
            printf("%s is surprising.\n", str);
        } else {
            printf("%s is NOT surprising.\n", str);
        }
    }
    return 0;
}
