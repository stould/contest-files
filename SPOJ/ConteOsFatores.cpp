#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

int i, j, primes[1000010];

int main(void) {
    ios::sync_with_stdio(false);
    vector<int> helper;
    memset(primes, 1, sizeof(primes));
    primes[0] = primes[1] = 0;
    for(i = 2; i <= (int) sqrt(1000000); i++) {
        if(primes[i]) {
            for(j = i*i; j <= 1000000; j += i) {
                primes[j] = false;
            }
        }
    }
    for(int i = 2; i <= (1000000); i++) {
        if(primes[i]) helper.push_back(i);
    }
    int aux;
    while(cin >> aux) {
        if(!aux) break;
        int tmp = aux, pos = 0;

        for(int i = 0; i < helper.size() && helper[i] <= tmp; i++) {
            bool flag = false;
            if(tmp % helper[i] == 0) {
                pos++;
            }
        }
        cout << aux << " : " << pos << endl;
    }

    return 0;


}
