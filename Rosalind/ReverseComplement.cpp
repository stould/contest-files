#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

string s;

int main(void) {
    freopen("i.in", "r", stdin);
    freopen("o.ot", "w", stdout);
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i]=='A') s[i] = 'T';
        else if(s[i]=='T') s[i] = 'A';
        else if(s[i]=='G') s[i] = 'C';
        else if(s[i] == 'C') s[i] = 'G';
    }
    reverse(s.begin(), s.end());
    cout << s << "\n";
    return 0;
}


