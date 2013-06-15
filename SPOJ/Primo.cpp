#include <iostream>
#include <math.h>

using namespace std;

int n;

int main(void) {
    cin >> n;
    n = abs(n);

    bool end = true;

    if (n <= 1) end = false;
    if (n == 2) end = true;
    if (n % 2 == 0) end = false;

    int m = (int) sqrt(n);

    if(!end) {
        cout << "nao" << endl; return 0;
    }

    for(int i = 3; i <= m; i += 2) {
        if n % i == 0) {
            cout << "nao" << endl; return 0;
        }
    }

    cout << "sim" << endl;

    return 0;
}
