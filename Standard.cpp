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
int T[110];

int main(void) {
<<<<<<< HEAD
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }

    int pg = 1;
    int pos = 0;

    int ans = 0;
    
    while (pos < N) {
        int cnt = 1;
        int used = 0;
        
        while (cnt <= T[pos]) {            
            if (cnt == pg) {
                ans += 1;
            }

            cnt += 1;
            used += 1;
            
            if (cnt % K == 0) {
                pg += 1;
                used = 0;
            }
        }
        if (used != 0) {
            pg += 1;
        }
        
        pos += 1;
    }

    cout << ans << "\n";
    
=======
>>>>>>> a23c852519b942b5dc0de8e348cb58d520e9c0e0
    return 0;
}
