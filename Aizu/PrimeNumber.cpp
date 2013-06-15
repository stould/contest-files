#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

bool s[100000];

void sieve() {
    memset(s, false, sizeof(s));
    s[0] = s[1] = true;
    for(int i = 2; i <= sqrt(999999); i++) {
        if(!s[i]) {
            for(int j = i * i; j <= 999999; j += i) {
                s[j] = false;
            }
        }
    }
}

int isPrime(int N) {
    int ans = 0;
    for(int i = 2; i <= N; i++) {
        if(sieve[i]) ans++;
    }
    return ans;
}

int main(void) {
    int N;
    sieve();
    while(cin >> N) {
        cout << isPrime(N) << endl;
    }
    return 0;
}
