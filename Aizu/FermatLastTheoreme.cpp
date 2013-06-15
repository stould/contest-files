#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>

using namespace std;

int z;

int main() {
    while(~scanf("%d", &z)) {
        if(z == 0) break;
        int i, j;
        int mx = 0;
        for(i = 1; i <= 1111; i++) {
            for(j = 1; j <= 1111; j++) {
                if((i*i*i) + (j*j*j) <= z*z*z) {
                    mx = max(mx, ((i*i*i) + (j*j*j)));
                }
            }
        }
        printf("%d\n", ((z*z*z) - mx));
    }
    return 0;
}
