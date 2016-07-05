#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stdio.h>

using namespace std;

int c, i, j, t, m, d, tmp;

struct diretor {
    int id;
    vector<int> keys;
    bool operator<(const diretor& d) const {
        return keys.size() < d.keys.size();
    }
};

int main(void) {
    freopen("i.in", "r", stdin);
    cin >> t;
    for( ; t-- > 0; ) {
        cin >> m >> d;
        vector<diretor> vd(d);
        for(i = 0; i < d; i++) {
            cin >> c;
            vd[i].id = i;
            for(j = 0; j < c; j++) {
                cin >> tmp; vd[i].keys.push_back(tmp);
            }
        }
        sort(vd.begin(), vd.end());
        set<int> now;
        int used = 0;
        for(i = 0; i < d; i++) {
            for(j = 0; j < vd[i].keys.size(); j++) {
                now.insert(vd[i].keys[j]);
                if(now.size() >= m) goto end;
            }
            used += 1;
        }
        end:;
        if(now.size() >= m) {
            cout << used << endl;
        } else {
            cout << "Desastre!" << endl;
        }
    }
    return 0;
}
