#include <string>
#include <iostream>
#include <cctype>

using namespace std;

int main() {
    string s;

    getline(cin, s);

    for(int i = 0; i < s.size(); i++) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            s[i] = toupper(s[i]);
        }
    }
    cout << s << endl;
    return 0;
}
