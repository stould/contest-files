#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

int i, j, n, a, b, mx;

map<int, int> check;
map<int, int> ex;

bool poss() {
    map<int, int>::iterator it = check.begin();
    for(; it != check.end(); it++) {
        if(it->second >= int(n / 2)) return true;
    }
    return false;
}

bool already() {
    map<int, int>::iterator it = ex.begin();
    for(; it != ex.end(); it++) {
        if(it->second >= int(n / 2)) return true;
    }
    return false;
}

int is() {
    map<int, int>::iterator it = check.begin();
    int ans = 0; mx = -1;
    for(; it != check.end(); it++) {
        if(it->second > ans) {
            mx = it->first;
            ans = it->second;
        }
    }
    return ans;
}

vector<pair<int, int> > vp;

int main(void) {
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> a >> b;
        vp.push_back(make_pair(a, b));
        check[a]++; check[b]++; ex[a]++;

    }
    if(n % 2 != 0) n++;
    if(!poss()) {
        cout << -1 << endl; return 0;
    } else if(already()) {
        cout << 0 << endl; return 0;
    }
    int ac = is(), act = 0; ac = 0;
    for(int i = 0; i < n; i++) if(vp[i].first == mx) ac++;
    for(int i = 0; i < n; i++) {
        if(vp[i].first != mx && vp[i].second == mx) {
            ac++; act++;
            if(ac >= int(n/2)) {
                break;
            }
        }
    }
    cout << act << endl;
    return 0;
}

