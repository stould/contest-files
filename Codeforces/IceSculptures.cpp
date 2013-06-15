#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <stdio.h>

using namespace std;

typedef long long ll;

struct St {
    int index;
    ll value;

    St() {}
    St(int id, ll v) {
        index = id;
        value = v;
    }
    bool operator<(const St& s) const {
        return value > s.value;
    }
};

int n;

int main(void) {
    freopen("i.in", "r", stdin);
    cin >> n;
    vector<St> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].value;
        v[i].index = i;
    }
    ll sum = 0;

    for(int i = 1; i < n; i++) {
        for(int k = 0; k + i < n; k++) {
            ll ac = 0;
            for(int j = k; j < n; j += i) {
                ac += v[j].value;
            }
            if(ac > sum) sum = ac;
        }
    }
    cout << sum << endl;
    return 0;
}
