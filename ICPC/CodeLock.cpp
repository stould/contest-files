#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

int main() {
    string s = "";
    int m = 0;

    while(s != "*") {
        getline(cin, s);
        int value = 0;
        for(int i = 0; i < s.size(); i++) {
            int j = i;
            while(j < s.size() && s[i] == s[j]) {
                j++;
            }
            value += min(s[i] - 'a', 'z' - s[i] + 1);
            i = j;
        }
        cout << value << endl;
    }
    return 0;
}
