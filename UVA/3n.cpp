#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int a, b;

int rec(int n) {
    int ct = 1;
    while(n != 1) {
        if(n % 2 == 0) {
            n /= 2;
        } else {
            n = (n * 3) + 1;
        }
        ct += 1;
    }
    return ct;
}

int main(void) {
    while(~scanf("%d%d", &a, &b)) {
        int ans = -1;
        for(int i = min(a, b); i <= max(a, b); i++) {
            ans = max(ans, rec(i));
        }
        printf("%d %d %d\n", a, b, ans);
    }
    return 0;
}
