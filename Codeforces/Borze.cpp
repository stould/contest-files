#include <iostream>

using namespace std;

int main() {
    string s, ans = "";
    getline(cin, s);

    for(int i = 0; i < s.size();) {
        if(s.substr(i, 2) == "-.") {
            ans += '1';
            i += 2;
        } else if(s.substr(i, 2) == "--") {
            ans += '2';
            i += 2;
        } else {
            ans += '0';
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}
