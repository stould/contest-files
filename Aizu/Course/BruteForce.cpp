#include <iostream>
#include <stdio.h>

using namespace std;

int n, q, v[30], m[300];

bool possible_subsets(int m) {
    for(int i = 0; i < (1 << n); i++) {
        int sum = 0;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                sum += v[j];
            }
        }
        if(sum == m) return true;
    }
    return false;
}

bool recursive(int p, int t) {
    if(p == n) return false;
    int sum = 0;
    for(int i = p; i < n; i++) sum += v[i];
    cout << p << " " << sum << " " << t << endl;
    if(sum == t) return true;
    recursive(p + 1, t - v[p]);
    recursive(p + 1, t);
}

int main(void) {
  //  freopen("i.in", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> m[i];
        if(recursive(0, m[i])) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}
