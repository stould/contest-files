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
     
template<typename T> void chmin (T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax (T& a, T b) { a = (a < b) ? b : a; }
     
int in (void) { int x; scanf("%d", &x); return x; }
using namespace std;
     
typedef long long Int;
typedef unsigned uint;
     
const int MAXN = 30;
const int MAXS = 1210;
     
int C, N;
int W[MAXN], P[MAXN];
string type[MAXN];
     
char buff[MAXS];
     
set<string>::iterator it;
     
int ok (char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
     
struct kind {
    set<string> words;
};
     
int main(void) {
    int i, j, x;
     
    N = in();
     
    for ( ; N--; ) {
        C = in();
     
        kind kbuff[C];
     
        for (x = 0; x < C; x++) {
            scanf("%s%d%d", buff, &W[x], &P[x]); type[x] = string(buff);
     
            for (i = 0; i < W[x]; i++) {
                scanf("%s", buff);
                kbuff[x].words.insert(string(buff));
            }
        }
     
        cin.ignore();
     
        set<string> st;
        string bf, aux;
     
        for ( ; getline(cin, aux); ) {
            if (aux.size() == 0) break;
            for (i = 0; i < aux.size(); i++) {
                if (ok(aux[i])) {
                    bf += aux[i];
                } else {
                    if (bf != "") {
                        st.insert(bf); bf = "";
                    }
                }
            }
            if (bf != "") {
                st.insert(bf); bf = "";
            }
        }
     
        int multiple = 0;
        vector<string> contains;
     
        for (x = 0; x < C; x++) {
            int cnt = 0;
            if (P[x] == 0) {
                contains.push_back(type[x]); multiple += 1;
                continue;
            }
            for (it = kbuff[x].words.begin(); it != kbuff[x].words.end(); it++) {
                if (st.count(*it)) {
                    cnt += 1;
                    if (cnt == P[x]) {
                        contains.push_back(type[x]);
                        multiple += 1;
                        break;
                    }
                }
            }
        }
     
        if (!multiple) {
            printf("SQF Problem\n");
        } else {
            for (i = 0; i < (int) contains.size(); i++) {
                if (i == (int) contains.size() - 1) {
                    printf("%s\n", contains[i].c_str());
                } else {
                    printf("%s,", contains[i].c_str());
                }
            }
        }
    }
    return 0;
}
