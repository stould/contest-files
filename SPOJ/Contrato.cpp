#include <iostream>
#include <sstream>
#include <stdio.h>

using namespace std;

int i, m[11000], p;
char d;
string n;

int main(void) {
    freopen("i.in", "r", stdin);
    while(cin >> d) {
        if(d == '0') break; cin >> n;
        for(i = 0; i < (int) n.size(); i++) if(n[i] == d) n[i] = ' ';
        i = 0; while(i < n.size() && (n[i] == '0' || n[i] == ' ')) { n[i] = ' '; i++; }
        p = 0;
        for(i = 0; i < (int) n.size(); i++) {
            if(n[i] == ' ') continue;
            m[p++] = n[i] - '0';
            cout << n[i];
        }
        if(p == 0) cout << "0";
        cout << endl;
    }
    return 0;
}
