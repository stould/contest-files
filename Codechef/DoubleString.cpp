#include <iostream>

using namespace std;

int main(void) {
    int n, t;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> t;
        if(t % 2 == 0) {
            cout << t << endl;
        } else {
            cout << (t - 1) << endl;
        }
    }
    return 0;
}
