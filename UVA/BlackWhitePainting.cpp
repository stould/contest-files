#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int n, m, c;

int main(void) {
    while(~scanf("%d%d%d", &n, &m, &c) && n > 0 && m > 0 && c > 0) {
        if(c == 0) {
            n -= 1; m -= 1;
        }

    }
    return 0;
}
