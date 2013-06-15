#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    string c;
    cin >> c;
    reverse(c.begin(), c.end());
    cout << c << endl;;
    return 0;
}

