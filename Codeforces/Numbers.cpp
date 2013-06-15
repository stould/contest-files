#include <string>
#include <iostream>
#include <cctype>

using namespace std;

int main() {
    int n;
    string s;
    vector<int> v;
    bool vt[100001];

    cin >> n;
    getline(cin, s);
    istringstream ss(s);

    while(ss >> temp) {
        v.push_back(temp);
    }


    return 0;
}

