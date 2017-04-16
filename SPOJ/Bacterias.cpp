#include <stdio.h>
#include <math.h>

int i, n, index, c, d;

int main(void) {
    scanf("%d", &n);
    double m = 0.0;
    for(i = 0; i < n; i++) {
        scanf("%d%d", &d, &c);
        if(m < (double) c * (double) log(d)) {
            m = (double) c * (double) log(d);
            index = i;
        }
    }
    printf("%d\n", index);
    return 0;
}
