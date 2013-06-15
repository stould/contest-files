#include <iostream>
#include <string>

using namespace std;

int main() {
    int i, j, ct, times = 0;
    string s;
    getline(cin, s);

    for(i = 0; i < s.size(); i++) {
        j = i;
        ct = 0;
        while(j < s.size() && ct < 5 && s[j] == s[i]) {
            ct++;
            j++;
        }
        times++;
        i = j - 1;
    }

    cout << times << endl;
    return 0;
}
