#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <stdio.h>

using namespace std;

typedef long double ld;

ld xa, ya, ra, xb, yb, rb;

int ans;

int main(void) {
    int N;
    scanf("%d", &N);

    while(N > 0) {
        cin >> xa >> ya >> ra >> xb >> yb >> rb;
        ans = 1;

        ld dist = sqrt(pow(xa - xb, 2) + pow(ya - yb, 2));

        if(dist + rb < ra) {
            ans = 2;
        } else if(dist + ra < rb) {
            ans = -2;
        } else if(dist > ra + rb) {
            ans = 0;
        }
        printf("%d\n", ans);
        N--;
    }

    return 0;
}
