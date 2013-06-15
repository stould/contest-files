#include <iostream>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int T, lenJ, lenS;
string s, j;
int main(void) {
    cin >> T;
    while(T--) {
        cin >> j >> s;
        map<char, int> ct;

        for(int i = 0; i < j.size(); i++) {
            ct[j[i]] += 1;
        }
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            if(ct[s[i]] > 0) {
                ans += 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
