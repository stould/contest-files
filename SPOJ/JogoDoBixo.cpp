#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <stdio.h>

using namespace std;

double v;
int n, m, in = 0;

int main(void) {
    map<int, int> mp;
    for(int i = 1; i <= 97; i += 4) {
        mp[i] = mp[i+1] = mp[i+2] = mp[i+3] = in++;
    } mp[0] = mp[97] = mp[98] = mp[99] = in + 1;
    while(cin >> v >> n >> m && !(v == 0 && n == 0 && m == 0)) {
        double ans = 0.0;
        int row = 0;
        int _n = n, _m = m;
        while(n > 0 || m > 0) {
            if(n % 10 != m % 10) break;
            if(n > 0) n /= 10;
            if(m > 0) m /= 10;
            row++;
        }
        if(row >= 4 || (_n == 0 && _m == 0)) {
            ans = v * 3000.0;
        } else if(row == 3) {
            ans = v * 500.0;
        } else if(row == 2) {
            ans = v * 50.0;
        } else {
            int a = ((_n % 10) * 1) + (((_n / 10) % 10) * 10);
            int b = ((_m % 10) * 1) + (((_m / 10) % 10) * 10);
            if(mp[a] == mp[b]) ans = v * 16.0;
        }
        printf("%.2f\n", ans);
    }
    return 0;
}

