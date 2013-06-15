#include <iostream>
#include <map>

using namespace std;

bool isLucky(string s) {
    for(int i = 0; i < (int) s.size(); i++) {
        if(s[i] != '4' && s[i] != '7') return false;
    }
    return true;
}

string get;
map<string, int> mp;

int main(void) {
    getline(cin, get);

    for(int i = 0; i < get.size(); i++) {
        for(int j = i; j < get.size(); j++) {
            string tmp(get.begin() + i, get.begin() + j);
            if(isLucky(tmp)) mp[tmp]++;
            string tmpa(get.begin() + i, get.begin() + j + 1);
            if(isLucky(tmpa)) mp[tmpa]++;
        }
    }

    int maximal = -1; string ans = "jhashduahdsuashduasdfhajsdhfljkshadflkjhdflkjasd";
    for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        if((*it).second >= maximal && (*it).first != "") {
            maximal = (*it).second;
            ans = (*it).first;
        }
    }
    for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        cout << (*it).first << " " << (*it).second << endl;
        if((*it).second == maximal && (*it).first < ans) {
            ans = (*it).first;
        }
    }
    if(ans == "jhashduahdsuashduasdfhajsdhfljkshadflkjhdflkjasd") {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
