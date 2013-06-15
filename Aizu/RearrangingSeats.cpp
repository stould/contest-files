#include <iostream>

using namespace std;

int r, c;

int main(void) {
    while(cin >> r >> c) {
        if(r == 0 && c == 0) break;
        if(!(r % 2 == 1 && c % 2 == 1)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}
