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

char buff[1007];
int ans, N, s[26], test = 1;

int main(void) {
    int i, j;
    char c;

    for ( ; scanf("%s", buff) && strcmp(buff, "end"); ) {
        N = strlen(buff);

        ans = 0;

        for (i = 0; i < 26; i++) s[i] = 50;

        for (i = 0; i < N; i++) {
            int best = -1, now = buff[i] - 'A';

            for (j = 0; j < 26; j++) {
                if (now < s[j] || (now == s[j] && best != -1 && s[j] < s[best])) {
                    best = j;
                }
            }

            s[best] = now;
        }

        for (i = 0; i < 26; i++) if (s[i] != 50) ans += 1;

        printf("Case %d: %d\n", test++, ans);
    }
    return 0;
}
