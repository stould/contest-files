#include <iostream>

using namespace std;

int n, t, v, all = 0;

int main(void) {
    cin >> n;
    while(n--) {
        cin >> t >> v;
        all += t * v;
    }
    cout << all << endl;
    return 0;
}
