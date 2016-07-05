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

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

int main(void) {
    int cnt = 0;
    int used = 0;
    bool is_power = false;
    
    for (int i = 0; used < 20 && i < 20; i++) {
        cout << primes[i] << "\n";
        cout << flush;

        string OT;
        cin >> OT;

        used += 1;

        if (OT == "yes") {
            cnt += 1;

            if (primes[i] * primes[i] <= 100) {
                cout << primes[i] * primes[i] << endl;
                cout << flush;
                used += 1;

                cin >> OT;

                if (OT == "yes") {
                    is_power = true;
                }
            }            
        }
    }

    if (cnt <= 1 && !is_power) {
        cout << "prime\n";
        cout << flush;
    } else {
        cout << "composite\n";
        cout << flush;
    }
    return 0;
}
