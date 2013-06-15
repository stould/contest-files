#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int x1, y_1, r1, x2, y2, r2;

int main(void) {
    cin >> x1 >> y_1 >> r1 >> x2 >> y2 >> r2;

    double ans = (double) (sqrt(((x1 - x2) * (x1 - x2)) + ((y_1 - y2) * (y_1 - y2))) - (r1 + r2)) / 2.0;

    if(ans <= r1 + r2) ans = 0.0;

    printf("%.15f\n", ans);

    return 0;
}
