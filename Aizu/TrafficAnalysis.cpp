#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int n, m, t;

int main(void) {
    while(cin >> n >> m) {
        if(n == 0 && m == 0) break;
        vector<int> a;
        a.push_back(0);
        for(int i = 0; i < n; i++) {
            cin >> t; a.push_back(t);
        }
        for(int i = 0; i < m; i++) {
            cin >> t; a.push_back(t);
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for(int i = 0; i + 1 < a.size(); i++) {
            if(fabs(a[i + 1] - a[i]) > ans) {
                ans = fabs(a[i + 1] - a[i]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
