#include <iostream>
#include <math.h>
#include <string.h>
#include <stdio.h>

using namespace std;

int primes[1000010];

int get_value(char c) {
    if(c >= 'a' && c <= 'z') {
        return c - 'a' + 1;
    }
    return c - 'A' + 27;
}

void sieve() {
    memset(primes, 1, sizeof(primes));
    primes[0] = 0;

    for(int i = 2; i <= (int) sqrt(1000000); i++) {
        if(primes[i]) {
            for(int j = i * i; j <= 1000000; j += i) {
                primes[j] = 0;
            }
        }
    }
}

string g;

int main(void) {
    sieve();
    while(cin >> g) {
        long long s = 0L;
        for(int i = 0; i < (int) g.size(); i++) {
            s += (long long) get_value(g[i]);
        }
        if(primes[s]) {
            cout << "It is a prime word." << endl;
        } else {
            cout << "It is not a prime word." << endl;
        }
    }
    return 0;
}
