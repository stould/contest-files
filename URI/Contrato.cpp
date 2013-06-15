#include <iostream>
#include <cstdio>

using namespace std;

char c;
string all;

int main(void) {
    ios::sync_with_stdio(false);
    while(cin >> c >> all && c != '0' && all != "0") {
        string ans = "";
        for(int i = 0; i < all.size(); i++) {
            if(all[i] != c) {
                if(ans == "" && all[i] == '0') continue;
                ans += all[i];
            }
        }
        if(ans == "") {
            ans = "0";
        }
        cout << ans << "\n";
    }
    return 0;
}
