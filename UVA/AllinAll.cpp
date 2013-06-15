#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

string s, t;

int main(void) {
    while(cin >> s >> t) {
        int j = 0, ct = 0;
        for(int i = 0; i < (int) s.size(); i++) {
            while(j < (int) t.size()) {
                if(s[i] == t[j]) {
                    ct += 1;
                    j += 1;
                    break;
                }
                j += 1;
            }
        }
        if(ct == s.size()) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
