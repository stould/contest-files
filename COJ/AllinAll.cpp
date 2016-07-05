#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

string s, t;

int main(void) {
    while(cin >> s >> t) {
        int i, index = 0;
        for(int i = 0; i < (int) t.size(); i++) {
            if(index < s.size()) {
                if(t[i] == s[index]) {
                    index += 1;
                }
            }
        }
        if(index == s.size()) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
