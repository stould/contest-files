#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int n, k, l, c, d, p, nl, np, m, liters, limes, salt;

int main(void) {
    scanf("%d%d%d%d%d%d%d%d", &n, &k, &l, &c, &d, &p, &nl, &np);

    liters = (int) (k * l) / nl;
    limes = (int) (c * d);
    salt = (p / np);

    m = min(liters, min(limes, salt));

    printf("%d\n", m / n);
    return 0;
}
