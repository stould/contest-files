#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
string s;

int main(void) {
    cin >> n >> s;

    if(s.size() <= 3) {
        cout << s << endl; return 0;
    }

    vector<char> ans;
    int i = 0;

    if(n % 2 == 0) {
        while(1) {
            if(i >= n) break;
            if(i + 2 < n) {
                ans.push_back(s[i]); ans.push_back(s[i + 1]); ans.push_back('-'); i += 2;
            } else {
                ans.push_back(s[i]); ans.push_back(s[i + 1]); i += 2;
            }
        }
    } else {
        ans.push_back(s[i]); ans.push_back(s[i + 1]); ans.push_back(s[i + 2]); ans.push_back('-'); i += 3;
        while(1) {
            if(i >= n) break;
            if(i + 2 < n) {
                ans.push_back(s[i]); ans.push_back(s[i + 1]); ans.push_back('-'); i += 2;
            } else {
                ans.push_back(s[i]); ans.push_back(s[i + 1]); i += 2;
            }
        }
    }
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
