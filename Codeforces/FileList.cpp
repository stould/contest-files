#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int i, j;
string s;

int main(void) {
    freopen("i.in", "r", stdin);
    cin >> s;
    vector<string> ans;

    for(i = 0; i < (int) s.size(); i++) {
        for(j = i + 1; j - i <= 8 && s[j] != '.'; j++) { }

        if(s.size() - j <= 3) {
            ans.push_back(s.substr(i, i - s.size()));
            break;
        } else {
            if(s[j + 3] != '.' && s[j + 2] != '.' && s[j + 1] != '.') {
                string tmp = s.substr(i, (j - i) + 4);
                if(tmp.find(".") == string::npos) {
                    cout << "NO" << endl; return 0;
                }
                ans.push_back(tmp);
                i = j + 3;
            } else if(s[j + 3] != '.' && s[j + 2] != '.') {
                string tmp = s.substr(i, (j - i) + 3);
                if(tmp.find(".") == string::npos) {
                    cout << "NO" << endl; return 0;
                }
                ans.push_back(tmp);
                i = j + 3;
            } else if(s[j + 2] != '.' && s[j + 1] != '.') {
                string tmp = s.substr(i, (j - i) + 2);
                if(tmp.find(".") == string::npos) {
                    cout << "NO" << endl; return 0;
                }
                ans.push_back(tmp);
                i = j + 2;
            } else {
                cout << "NO" << endl; return 0;
            }
        }
     }
     cout << "YES" << endl;
     for(i = 0; i < (int) ans.size(); i++) {
        cout << ans[i] << endl;
     }
    return 0;
}
