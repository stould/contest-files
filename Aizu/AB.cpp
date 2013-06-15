#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
    int a, b;
    while(scanf("%d %d", &a, &b) != EOF) {
        cout << (a + b) << endl;
    }
    return 0;
}
