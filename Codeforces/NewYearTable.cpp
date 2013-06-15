#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int n, R, r;

    cin >> n >> R >> r;

    if(((n * r) / 2) < R) {
        cout << "YES" << endl;
    } else {
        cout << "NO";
    }

    return 0;
}
