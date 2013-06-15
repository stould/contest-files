#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;

int i, j, c;
string s;

int main(void) {
    cin.ignore();
    while(getline(cin, s)) {
        c = 0;
        for(i = 0; i < (int) s.size(); i++) {
            bool ok = false;
            j = i;
            while(j < (int) s.size() && s[j] >= 'a' && s[j] <= 'z' || s[j] >='A' && s[j] <= 'Z') {
                ok = true;
                j++;
            }
            i = j;
            if(ok) {
                c++;
            }
        }
        cout << c << endl;
    }
    return 0;
}
