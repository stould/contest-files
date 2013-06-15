#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>

using namespace std;

const int N = 1001;
typedef long long ll;

ll mem[1000];

ll f(int n) {
    ll u = 0L, v = 1L;

    for(int i = 0; i < n; i++) {
        ll save = u;
        u = v;
        v = save + v;
    }
    return u;
}

int v, d;

int main(void) {
    while(cin >> v >> d) {
        for(int i = 1; i < v; i++) {
            mem[i] = (f(i) % N);
            printf("%lld\n", mem[i]);
        }
    }
    return 0;
}
