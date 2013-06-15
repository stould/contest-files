#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int n, k;

bool isPrime(int n) {
    if(n <= 1) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;

    int m = (int) sqrt(n);

    for(int i = 3; i <= m; i+=2) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(void) {
    cin >> n >> k;
    vector<int> primes;
    for(int i = 1; i <= n; i++) {
        if(isPrime(i)) {
            primes.push_back(i);
        }
    }
    int count = 0;
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < primes.size() - 1; j++) {
            if(1 + primes[j] + primes[j + 1] == i && isPrime(i)) {
                count++; break;
            }
        }
    }
    if(count >= k) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
