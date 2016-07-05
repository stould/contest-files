#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <functional>
#include <limits>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <valarray>
#include <vector>
#include <utility>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define REP(i, n) for((i) = 0; (i) < (n); i++)
#define FOR(i, a, n) for((i) = (a); (i) < (n); i++)

using namespace std;

const int INF = 1000000000;
const double PI = acos(-1);

typedef long long ll;

int i, j, n, e, f;
string str;

string lower(string s) {
    int i;
    REP(i, s.size()) {
        s[i] = tolower(s[i]);
    }
    return s;
}

int main(void) {
    scanf("%d", &n);
    while(n-- > 0) {
        scanf("%d%d", &e, &f);
        vector<string> ve;
        REP(i, e) {
            cin >> str;
            ve.push_back(lower(str));
        }
        cin.ignore();
        REP(i, f) {
            getline(cin, str);
            REP(j, str.size()) {
                int k = j;
                if(str[k] == ' ' || str[k] == ':' || str[k] == '-') continue;
                while(k < str.size() && str[k] != ' ' && str[k] != ':' && str[k] != '-') {
                    k++;
                }
                string help = lower(str.substr(j, k - j));
                if(find(ve.begin(), ve.end(), help) != ve.end()) {
                    if(j != 0) {
                        putchar(tolower(str[j]));
                    }
                } else {
                    putchar(toupper(str[j]));
                }
                j = k;
            }
            puts("");
        }
        puts("");
    }
    return 0;
}

