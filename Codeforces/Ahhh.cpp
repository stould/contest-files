#include <bits/stdc++.h>

using namespace std;

string S[2];

int main() {
    cin >> S[0] >> S[1];

    if (S[0].size() >= S[1].size()) {
        cout << "go\n";
    } else {
        cout << "no\n";
    }
    return 0;
}
