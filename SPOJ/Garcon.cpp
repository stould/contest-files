#include <iostream>

using namespace std;

int n, l, c, all = 0;

int main(void) {
    cin >> n;
    while(n--) {
        cin >> l >> c;
        if(l > c) {
            all += c;
        }
    }
    cout << all << endl;
    return 0;
}
