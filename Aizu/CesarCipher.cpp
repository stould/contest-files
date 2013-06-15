#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string decode(string s, int v) {
    string ans = s;
    for(int i = 0; i < (int) s.size(); i++) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            ans[i] = (s[i] + v) % 26 + 'a';
        }
    }
    return ans;
}

int main() {
    string s;
    while(getline(cin, s)) {
        for(int i = 0; 26; i++) {
            string tmp = decode(s, i);
            if(tmp.find("this") != string::npos || tmp.find("the") != string::npos || tmp.find("that") != string::npos) {
                cout << tmp << endl;
                break;
            }
         }
    }
    return 0;
}
