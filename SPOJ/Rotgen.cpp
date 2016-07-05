#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <stdio.h>

using namespace std;

int i, j, x, k;
string n;

string itostr(int n) {
    string ans = "";
    while(n > 0) {
        ans = (char) ((n % 10) + '0') + ans;
        n /= 10;
    }
    return ans;
}

int main(void) {
  //  freopen("i.in", "r", stdin);
  //  freopen("rt.out", "w", stdout);
    cin >> x;
    bool ok = false;
    while(x-- > 0) {
        if (ok) cout << endl;
        ok = true;
        cin >> n >> k;
        while(k-- > 0) {
            cout << n << endl;
            map<char, int> mp;
            string novo = "";
            for(i = 0; i < n.size(); i++) {
                int count = 0;
                for(j = i; n[i] == n[j] && j < n.size(); j++) {
                    count += 1;
                }
                novo += itostr(count);
                novo += n[i];
                i = j - 1;
            }
            n = novo;
        }
        cout << n << endl;
    }
    return 0;
}
