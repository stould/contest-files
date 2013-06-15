#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

int main() {
    int n, temp, count = 0;
    string s;
    vector<long long> numbers, valids;

    cin >> n;

    getline(cin, s);
    getline(cin, s);

    istringstream ss(s);

    while(ss >> temp) {
        numbers.push_back(temp);
    }

    int tot = 0, v = numbers.size() - 1;

    for(int i = 0; i < numbers.size(); i++) {
        tot += numbers[i];
    }

    if(tot % n != 0) {
        cout << "0" << endl;
    } else {
        for(int j = 0; j < numbers.size(); j++) {
            if(numbers[j] == tot / n) {
                count++;
                valids.push_back(j + 1);
            }
        }

        cout << count << endl;

        for(int i = 0; i < valids.size(); i++) {
            cout << valids[i] << " ";
        }
    }
    return 0;
}
