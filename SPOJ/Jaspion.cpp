#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <iostream>
#include <functional>
#include <limits>
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

string a, b;
int i, j, k, t, n, m, x;

vector<string> split(string& s) {
    stringstream ss(s);
    string tmp;
    vector<string> ans;
    while(ss >> tmp) {
        ans.push_back(tmp);
    }
    return ans;
}

int main(void) {
    scanf("%d", &t);
    for(x = 0; x < t; x++) {
        map<string, string> mp;
        vector<string> str;
        scanf("%d%d", &n, &m);
        cin.ignore();
        REP(i, n) {
            getline(cin, a); getline(cin, b);
            str.push_back(a);
            mp[a] = b;
        }
        REP(i, m) {
            getline(cin, a);
            vector<string> tmp = split(a);
            REP(j, tmp.size()) {
                REP(k, str.size()) {
                    if(tmp[j] == str[k]) {
                        tmp[j] = mp[tmp[j]];
                        break;
                    }
                }
            }
            REP(j, tmp.size()) {
                if(j == tmp.size() - 1) {
                    cout << tmp[j] << "\n";
                } else {
                    cout << tmp[j] << " ";
                }
            }
        }
        if(x != t - 1) cout << "\n";
    }
    return 0;
}
