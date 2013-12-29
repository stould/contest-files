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

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

int D;
char opt, buff[109];

map<string, int> s_i;
map<int, string> i_s;

void build (void) {
    i_s[1] = "*....."; s_i["*....."] = 1;
    i_s[2] = "*.*..."; s_i["*.*..."] = 2;
    i_s[3] = "**...."; s_i["**...."] = 3;
    i_s[4] = "**.*.."; s_i["**.*.."] = 4;
    i_s[5] = "*..*.."; s_i["*..*.."] = 5;
    i_s[6] = "***..."; s_i["***..."] = 6;
    i_s[7] = "****.."; s_i["****.."] = 7;
    i_s[8] = "*.**.."; s_i["*.**.."] = 8;
    i_s[9] = ".**..."; s_i[".**..."] = 9;
    i_s[0] = ".***.."; s_i[".***.."] = 0;
}

int main(void) {
    int i, x, ok = 0;

    build ();

    for ( ; scanf("%d", &D) == 1; ) {
        scanf(" %c", &opt);

        if (ok) printf("\n");

        ok = 1;

        if (opt == 'S') {
            scanf("%s", buff);

            for (x = 0; x < 3; x++) {
                int id = x == 0 ? 0 : x == 1 ? 2 : 4;
                for (i = 0; i < D; i++) {
                    if (i != D - 1) {
                        printf("%s ", i_s[buff[i]-'0'].substr(id, 2).c_str());
                    } else {
                        printf("%s", i_s[buff[i]-'0'].substr(id, 2).c_str());
                        if (x != 2) printf("\n");
                    }
                }
            }
        } else {
            string s[D];
            for (x = 0; x < 3; x++) {
                for (i = 0; i < D; i++) {
                    scanf("%s", buff);
                    s[i] += string(buff);
                }
            }

            for (i = 0; i < D; i++) {
                printf("%d", s_i[s[i]]);
            }
        }
    }

    return 0;
}
