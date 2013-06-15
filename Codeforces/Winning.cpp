#include <iostream>
#include <map>
#include <stdio.h>

using namespace std;

int i, n, tmp, vm[110000];
string sm[110000];

int main(void) {
    cin >> n;
    map<string, int> mp, aux;
    int mx = -100000000;
    string ans = "";
    for(i = 0; i < n; i++) {
        cin >> sm[i] >> vm[i];
        mp[sm[i]] += vm[i];
    }
    for(i = 0; i < n; i++) {
        if(mp[sm[i]] > mx) {
            mx = mp[sm[i]];
        }
    }
    for(i = 0; i < n; i++) {
        aux[sm[i]] += vm[i];
        if(aux[sm[i]] >= mx && mp[sm[i]] == mx) {
            cout << sm[i] << endl;
            break;
        }
    }
    return 0;
}
