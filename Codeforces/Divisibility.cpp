#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAX_TRY = 100;

Int N;

Int modPow(Int a, Int n, Int mod) {
    Int res = 1;
    while (n) {
        if (n & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        n /= 2;
    }
    res %= mod;
    res += mod;
    res %= mod;
    
    return res;
}

Int llrand(){
    Int a = rand();
    a<<=32;
    a+=rand();
    return a;
}

bool is_probably_prime(Int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;

    Int s = 0, d = n - 1;
    
    while (d % 2 == 0) {
        d /= 2;
        s++;        
    }

    for(int k = 0; k < 512; k++) {
        Int a = (llrand() % (n - 3)) + 2;
        Int x = modPow(a, d, n);

        if (x != 1 && x != n - 1) {
            for (int r = 1; r < s; r++) {
                x = modPow(x, 2, n);
                
                if(x == 1) {
                    return 0;
                }
                if (x == n - 1) {
                    break;
                }
            }

            if (x != n - 1) {
                return 0;                
            }
        }
    }
    
    return 1;    
}
Int rho(Int n) {
    Int d, c = rand() % n, x = rand() % n, xx = x;
    if (n % 2 == 0) {        
        return 2;
    }

    do {
        x = (modPow(x, x, n) + c) % n;
        xx = (modPow(xx, xx, n) + c) % n;
        xx = (modPow(xx, xx, n) + c) % n;
        d = gcd(abs(x - xx) , n);
    } while (d == 1);
    
    return d;
}

map <Int, int > F;

void factor (Int n) {
    //    cout << n << endl;
    if (n == 1) {
        return;
    }
    if (is_probably_prime(n)) {
        F[n]++;
        return;
    }
    Int d = rho(n);

    while (d == n) {
        d = rho(n);
    }
    factor(d);
    factor(n / d);
}

int main(void) {
    cin >> N;

    srand(time(NULL));

    if (is_probably_prime(N)) {
        cout << 2 << endl;
    } else {
        return 0;
        factor(N);

        Int ans = 1;

        for (auto& it : F) {
            ans *= (it.second + 1);
        }

        cout << ans << endl;
    }
    return 0;
}
