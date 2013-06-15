#include <iostream>
#include <stdio.h>

using namespace std;

string s;

int main(void) {
    freopen("i.in", "r", stdin);
    freopen("o.ot", "w", stdout);
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i]=='T') s[i] = 'U';
        cout << s[i];
    } cout << "\n";
    return 0;
}

