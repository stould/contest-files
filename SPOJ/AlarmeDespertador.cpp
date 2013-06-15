#include <iostream>

using namespace std;

int h1, m1, h2, m2;

int main(void) {
    while(cin >> h1 >> m1 >> h2 >> m2) {
        if(!h1 && !m1 && !h2 && !m2) break;

        int before = (h1 * 60) + m1;
        int after = (h2 * 60) + m2;

        cout << (after - before) << endl;
    }
    return 0;
}
