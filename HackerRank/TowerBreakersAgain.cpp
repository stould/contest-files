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

const int MAXN = 105;
const int MAXV = 1000005;

int T, N;
int P[MAXN];
int isP[MAXV];

vector<int> primes;

int dv(int x) {
    int pr = 0;

    if (x % 2 == 0) pr += 1;
    
    for (int i = 1; i < (int) primes.size(); i++) {
        if (x % primes[i] == 0) {
            int cnt = 0;
            
            while (x % primes[i] == 0) {
                cnt += 1;
                x /= primes[i];
            }

            pr += cnt;
        }
    }
    
    return pr;
}

int grundy(int x) {
    if (x == 1) return 0;

    set<int> s;

    for (int i = 2; i <= x; i++) {
        if (x % i == 0) {
            if (i % 2 == 0) {
                s.insert(0);
            } else {
                s.insert(grundy(x / i));
            }
        }
    }
    
    int ans = 0;

    while (s.count(ans)) ans += 1;

    return ans;
}

int main(void) {
    for (int i = 2; i < MAXV; i++) {
        if (!isP[i]) {
            primes.push_back(i);

            for (Int j = i * (Int) i; j < MAXV; j += i) {
                isP[j] = true;
            }
        }
    }


    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;

        int x = 0;
        
        for (int i = 0; i < N; i++) {
            cin >> P[i];
            x ^= dv(P[i]);
        }
        
        if (x == 0) {
            cout << "2" << endl;
        } else {
            cout << "1" << endl;
        }
    }
    return 0;
}
