#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    int n, temp;
    vector<int> v;
    vector<int>::iterator it;
    string s;
    stringstream ss;

    cin >> n;
    getline(cin, s);
    getline(cin, s);

    ss << s;

    while(ss >> temp) { v.push_back(temp); }

    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v.size(); j++) {
            if(i + 1 == v[j]) {
                cout << j + 1 << " ";
                break;
            }
        }
    }

    return 0;
}
