#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    int n, temp;
    vector<int> v;

    string s;
    stringstream ss;

    cin >> n;
    getline(cin, s); getline(cin, s);

    ss << s;

    while(ss >> temp) { v.push_back(temp); }

    int tmp = *min_element(v.begin(), v.end());

    if(tmp != 1) {
        *find(v.begin(), v.end(), tmp) = 1;
    } else {
        tmp = 1000000;
        for(int i = 0; i < v.size(); i++) {
            if(v[i] != 1 && v[i] < tmp) tmp = v[i];
        }
        *find(v.begin(), v.end(), tmp) = 1;
    }

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}

