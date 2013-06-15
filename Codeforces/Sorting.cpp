#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef long long ll;

ll i, j, index, n, v[1001010], dif = 0L;

int main(void) {
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> v[i];
        if(i > 0 && v[i - 1] > v[i]) dif += (v[i - 1] - v[i]);
    }
    printf("%I64d\n", dif);
    return 0;
}

