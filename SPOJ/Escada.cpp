#include <iostream>

using namespace std;

int i, n, l, s, all = 0;

int main(void) {
    cin >> n >> l; all += 10;
    for(i = 0; i < n - 1; i++) {
        cin >> s;
        if(s - l < 10) {
            all += s - l;
        } else {
            all += 10;
        }
        l = s;
    }
    cout << all << endl;
    return 0;
}
