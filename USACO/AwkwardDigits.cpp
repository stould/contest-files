#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

string toDec(string s, int actual) {
    string ans;
    stringstream ss;
    for(int i = s.size() - 1, acc = 0; i >= 0; i--, acc++) {
        ss << (s[i] - '0') * pow(actual, acc);
    }
    ss >> ans;
    return ans;
}

int main() {
    string bin, tri;

    cin >> bin >> tri;

    for(int i = 0; i < )

    return 0;
}
