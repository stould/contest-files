#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <stdlib.h>

#define MAX 1048576

using namespace std;

int n, test = 1;
vector<int> primes;

void sieve() {
    vector<bool> help(MAX+1, true);
    help[0] = help[1] = false;
    for(int i = 2; i <= (int) sqrt(MAX); i++) {
        if(help[i]) {
            for(int j = i * i; j <= MAX; j += i) {
                help[j] = false;
            }
        }
    }
    for(int i = 2; i <= MAX; i++) if(help[i]) primes.push_back(i);
}

int main(void) {
    sieve();
    while(cin >> n) {
        int fact = 0, exp = 0;
        vector<bool> already(n, false);
        while(n > 1) {
            for(int i = 0; i < primes.size(); i++) {
                if(n % primes[i] == 0) {
                    if(!already[primes[i]]) {
                        already[primes[i]] = true;
                        fact++;
                    }
                }
                exp++;
                n /= primes[i]; break;
            }
        }
        cout << "Instancia " << test++ << endl;
        if(fact >= 2 && exp >= 4) {
            cout << "sim\n\n";
        } else {
            cout << "nao\n\n";
        }
    }
    return 0;
}
