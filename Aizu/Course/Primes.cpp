#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

int n, s, ans = 0;

bool isPrime(int a) {
    if(a <= 1 || (a % 2 == 0 && a != 2)) return false;
    if(a == 2) return true;

    for(int i = 3; i <= (int) sqrt(a); i += 2) {
        if(a % i == 0) return false;
    }
    return true;
}

int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        if(isPrime(s)) {
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}
