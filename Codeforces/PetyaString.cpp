#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

#define REP(i, n) for(i = 0; i < n; i++)

using namespace std;

int main() {
    int i;
    string s1;
    string s2;

    getline(cin, s1);
    getline(cin, s2);

    int n = s1.size();

    REP(i, n) {
        s1[i] = tolower(s1[i]);
        s2[i] = tolower(s2[i]);
    }

    if(s1 < s2) {
        cout << - 1 << endl;
    } else if(s1 == s2) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }
    return 0;
}
