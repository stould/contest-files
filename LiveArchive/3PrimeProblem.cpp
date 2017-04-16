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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 1010;

int T, N;
int p[MAXN];
vector<int> primes;

int main(void) {
    cin >> T;

    for (int i = 2; i < MAXN; i++) {
        if (!p[i]) {
            primes.push_back(i);
            for (int j = i + i; j < MAXN; j += i) {
                p[j] = true;
            }
        }
    }

    while (T--) {
        cin >> N;
        bool ok = false;
        
        for (int i = 0; i < (int) primes.size(); i++) {
            for (int j = i; j < (int) primes.size(); j++) {
                for (int k = j; k < (int) primes.size(); k++) {
                    if (primes[i] + primes[j] + primes[k] == N) {
                        cout << primes[i] << " " << primes[j] << " " << primes[k] <<"\n";
                        ok = true;
                        goto end;
                    }
                }
            }
        }
    end:;
        if (!ok) {
            cout << "0\n";
        }        
    }
    return 0;
}
