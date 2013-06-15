#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int main() {
    string n;
    int i, value = 0, times = 0;

    getline(cin, n);

    while(n.size() >= 2) {
        for(i = 0; i < n.size(); i++) {
            value += n[i] - '0';
        }
        ostringstream ss;
        ss << value;
        n = ss.str();
        value = 0;
        times++;
    }
    cout << times;
    return 0;
}
