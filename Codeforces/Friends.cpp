#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include <stdio.h>

#define REP(i, a, n) for(i = a; i < (n); i++)

using namespace std;

typedef long long ll;

int n, d, c, i, j;
string a, b;

string f[1010], t[1010];
int v[1010];

set<pair<string, string> > ans;
set<pair<string, string> >::iterator it;

int main(void) {
    cin >> n >> d;
    REP(i, 0, n) {
        cin >> a >> b >> c;
        f[i] = a;
        t[i] = b;
        v[i] = c;
    }

    REP(i, 0, n) {
        REP(j, i + 1, n) {
            if(f[i] == t[j] && t[i] == f[j] && v[j] - v[i] <= d && v[j] - v[i] > 0) {
                if(f[i] < f[j]) {
                    ans.insert(make_pair(f[i], f[j]));
                } else {
                    ans.insert(make_pair(f[j], f[i]));
                }
            }
        }
    }
    cout << ans.size() << endl;
    for(it = ans.begin(); it != ans.end(); it++) {
        cout << (*it).first.c_str() << " " << (*it).second.c_str() << endl;
    }
    return 0;
}
