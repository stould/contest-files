#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

int R, n, data[3];

int main(void) {
    while(1) {
        scanf("%d%d%d", &data[0], &data[1], &data[2]);
        if(data[0] == 0 && data[1] == 0 && data[2] == 0) break;

        sort(data, data + 3);

        scanf("%d", &n);

        while(n > 0) {
            scanf("%d", &R);
            if(R * 2 > sqrt(data[0] * data[0] + data[1] * data[1])) {
                printf("OK\n");
            } else {
                printf("NA\n");
            }
            n--;
        }
    }
    return 0;
}
