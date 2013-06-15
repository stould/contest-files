#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int n, v[101];

int main(void) {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
        }
        sort(v, v + n);
        int am = 0;
        for(int i = 0; i < n; i++) {
            int tmp = 0;
            for(int j = i; j >= 0; j--) {
                tmp += v[j];
            }
            am += tmp;
        }
        printf("%d\n", am);
    }
    return 0;
}
