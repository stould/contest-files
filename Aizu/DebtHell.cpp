#include <iostream>

using namespace std;

typedef long long ll;

int n, base = 100000;

int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        base = base + base * 0.05;
        if(base % 1000 != 0) {
            base += 1000 - (base %1000);
        }
    }
    cout << base << endl;
    return 0;
}
