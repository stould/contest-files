#include <iostream>
#include <stdio.h>

using namespace std;

int a, b;

int main(void) {
    while(1) {
        cin >> a >> b;
        if(!a && !b) break;

        int carry = 0, summie = 0;

        while(a || b) {
            int diva = 0, divb = 0;
            if(a > 0) {
                diva = a % 10;
                a /= 10;
            }
            if(b > 0) {
                divb = b % 10;
                b /= 10;
            }
            if(diva + divb + summie >= 10) {
                carry++;
                summie = (diva + divb + summie) / 10;
            } else {
                summie = 0;
            }
        }
        if(carry == 0) {
            cout << "No carry operation." << endl;
        } else {
            if(carry == 1) {
                cout << carry << " carry operation." << endl;
            } else {
                cout << carry << " carry operations." << endl;
            }
        }
    }
    return 0;
}
