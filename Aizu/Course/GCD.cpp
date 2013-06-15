#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if(b == 0L) return a;
    return gcd(b, a % b);
}

ll a, b;

int main(void) {
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    return 0;
}
