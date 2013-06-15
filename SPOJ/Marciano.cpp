#include <iostream>
#include <math.h>

using namespace std;

int l, a, p, r;

int main(void) {
    cin >> l >> a >> p >> r;

    double fd = (double) sqrt((l*l) + (p*p));
    double pd = (double) sqrt((a*a) + (fd*fd));

    if(pd <= (double) (r*2) + 1e-9) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }
    return 0;
}
