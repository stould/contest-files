#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;

int i, j, k, n;
string s;

void print(int ma, int mi) {
    printf("The maximum and minimum are %d and %d.\n", ma, mi);
}

int main(void) {
    cin >> n;
    for(i = 0; i < 3; i++) {
        cin >> s;
        int ma = 0, mi = 0;

        print(ma, mi);
    }
}
