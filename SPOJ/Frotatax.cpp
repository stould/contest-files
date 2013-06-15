#include <iostream>
#include <vector>

using namespace std;

double la, lg, kla, klg;

int main(void) {
    cin >> la >> lg >> kla >> klg;

    double ra = (double) kla / (double) la;
    double rg = (double) klg / (double) lg;

    if(rg >= ra) {
        cout << "G" << endl;
    } else {
        cout << "A" << endl;
    }

    return 0;
}
