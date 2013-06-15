#include <iostream>

using namespace std;

int n, m, a;

int main(void) {
    cin >> n >> m >> a;

    cout << (int) (((n / a) + 0.5) + ((m / a) + 0.5)) * (((n / a) + 0.5) + ((m / a) + 0.5)) << endl;

    return 0;
}
