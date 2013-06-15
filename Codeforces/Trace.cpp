#include <algorithm>
#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

typedef long long ll;

const double PI = 3.141592653589793;

int n, radius[101];

double area(int r) {
    return PI * r * r;
}

int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> radius[i];

    sort(radius, radius + n); reverse(radius, radius + n);

    double all = area(radius[0]);

    for(int i = 1; i < n; i++) {
        if(i % 2 == 0) {
            all += area(radius[i]);
        } else {
            all -= area(radius[i]);
        }
    }
    printf("%.15f\n", all);
    return 0;
}
