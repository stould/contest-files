#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string s;
int k;

int match(string s, string b) {
    for(int i = 0; i < (int) s.size() - 1; i++) {
        if(((s[i] == b[0] && s[i + 1] == b[1]) || (s[i] == b[1] || s[i + 1] == b[0])) return i;
    }
    return -1;
}

int main(void) {
    cin >> s;
    cin >> k;
    vector<string> fb(k);
    for(int i = 0; i < k; i++) {
        cin >> fb[i];
    }

    for(int i = 0; i < k; i++) {
        int tmp = match(s, fb[i])
        if(tmp != -1) {
            int mr = 0, ml = 0, j;
            j = tmp - 1;
            while(j >= 0 && s[j] == s[tmp + 1]) {j -= 1; ml += 1;}
            j = tmp + 1;
            while(j < s.size() && s[j] == s[tmp]) {j += 1; mr += 1;}
        }
    }

    return 0;
}

