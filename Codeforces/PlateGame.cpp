#include <iostream>

using namespace std;

int a, b, r;

int main(void) {
    cin >> a >> b >> r;
    int radius = r * 2;

    if(a < radius || b < radius) {
        cout << "Second" << endl;
    } else {
        cout << "First" << endl;
    }
    return 0;
}
