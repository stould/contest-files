#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int n, tmp;

int main(void) {
    cin >> n;
    double orange = 0., all = 0.;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        all += 100.;
        orange += (double) tmp;
    }
    printf("%.9f\n", (double)(orange*100.0/all));
    return 0;
}
