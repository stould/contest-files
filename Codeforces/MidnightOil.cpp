#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <utility>
#include <math.h>
using namespace std;

typedef long long ll;

ll n, k, v;

int main(void) {
    cin >> n >> k;
    ll low = 1, high = 1000000000ll, tmp = k, mid;

    while(low < high) {
        mid = (low + high) / 2;
        ll sum = 0, m = 1;
        while(1) {
            sum += mid / m;
            if(mid / m == 0) break;
            m *= k;
        }
        if(sum >= n) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << high << endl;

    return 0;
}

