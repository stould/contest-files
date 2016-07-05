#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int n;
string s;
vector<string> v;
map<string, int> mp;

int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        if(mp[s] == 0) {
            cout << "OK" << endl;
            mp[s] += 1;
        } else {
            cout << s << mp[s] << endl;
            mp[s] += 1;
        }
    }
    return 0;
}
