#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long ll;

const double PI = 3.141592653589793;


int main(void) {
    int n; cin >> n;
    double red = 0, blue = 0;

    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        if(i == 0) { red += tmp*tmp; continue; }
        if(i % 2 == 0) {
            blue += tmp*tmp;
        } else {
            red += tmp*tmp;
        }
    }
    printf("%.15f\n", abs((red - blue) * PI));
    return 0;
}

