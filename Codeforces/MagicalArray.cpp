#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, temp, ret = 0;
    string c;

    vector<int> v;

    cin >> n;

    getline(cin, c);
    getline(cin, c);

    istringstream ss(c);

    while(ss >> temp) { v.push_back(temp); }

    ret += n;

    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v.size(); j++) {
            if(i < j && v[i] == v[j]) {
                ret++;
            }
        }
    }

    cout << ret << endl;
    return 0;
}
