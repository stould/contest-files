#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

map<char, string> m;

const int MOD = 1000003;

int main() {
    m['>'] = "1000";
    m['<'] = "1001";
    m['+'] = "1010";
    m['-'] = "1011";
    m['.'] = "1100";
    m[','] = "1101";
    m['['] = "1110";
    m[']'] = "1111";

    string s, sum;

    getline(cin, s);

    for(int i = 0; i < s.size(); i++) {
        sum += m[s[i]];
    }

    long long v = 0;

    for(int i = sum.size() - 1; i >= 0; i--) {
        if(sum[i] == '1') {
            v += (long long) (1 << (sum.size() - 1) - i) % MOD;
        }
    }

    cout << (v) << endl;

    return 0;
}

