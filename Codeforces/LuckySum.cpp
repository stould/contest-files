#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

const int INF = 1 >> 9;

long long memo[INF];

long long next(long long);
void fnext(long long);

int main() {
    long long l, r, sum = 0;

    memset(memo, 0, sizeof memo);

    scanf("%I64d %I64d", &l, &r);

    for(long long i = l; i <= r; i++) {
        cout << next(l) << endl;
    }

    printf("%I64d", sum);
    return 0;
}

long long next(long long n) {
    if(memo[n] != 0) {
        return memo[n];
    } else {
        fnext(n);
        return memo[n];
    }
}

void fnext(long long n) {
    for(long long i = n; ; i++) {
        long long temp = i;
        bool valid = true;

        while(temp > 0) {
            if(temp % 10 != 4 && temp % 10 != 7) {
                valid = false;
                break;
            }
            temp /= 10;
        }
        if(valid) {
            for(long long j = n; j <= i; j++) {
                memo[j] = i;
            }
            break;
        }
    }
}
