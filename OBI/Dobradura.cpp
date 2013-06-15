#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

int n, t = 1;

int main(void) {
    while(1) {
        cin >> n; if(n == -1) break;
        int base = 2, aux = 1;
        for(int i = 1; i <= n; i++) {
            base += aux; aux *= 2;
        }
        cout << "Teste " << t << endl << (base*base) << endl;
        t++;
    }
    return 0;
}
