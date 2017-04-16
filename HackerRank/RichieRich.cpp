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

int N, K;
string S;

int main(void) {
    cin >> N >> K >> S;

    int need = 0;
    
    for (int i = 0; i < N / 2; i++) {
        if (S[i] != S[N - i - 1]) {
            need += 1;
        }
    }

    if (K < need) {
        cout << "-1\n";
    } else {
        int spare = K - need;
        
        for (int i = 0; i < N / 2; i++) {
            int nd = 0;
            
            if (S[i] != '9')         nd += 1;
            if (S[N - i - 1] != '9') nd += 1;

            if (spare >= nd) {            
                S[i] = S[N - i - 1] = '9';
                spare -= nd;
                K -= nd;
            }
        }

        if (spare > 0) {
            S[N / 2] = '9';
            K -= 1;
            spare -= 1;
        }

        for (int i = 0; i < N / 2 && K > 0; i++) {
            if (S[i] != S[N - i - 1]) {
                S[i]         = max(S[i], S[N - i - 1]);
                S[N - i - 1] = max(S[i], S[N - i - 1]);
                K -= 1;
            }
        }

        for (int i = 0; i < N / 2 && K >= 2; i++) {
            if (S[i] != '9') {
                S[i] = S[N - i - 1] = '9';
                K -= 2;
            }
        }
        
        cout << S << "\n";
    }
    
    return 0;
}
