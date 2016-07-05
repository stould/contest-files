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

int N;
int sum[2][500];

int main(void) {
    cin >> N;

    string G;
    int A, B;
    
    for (int i = 0; i < N; i++) {
        cin >> G >> A >> B;

        int row = G == "M" ? 0 : 1;
        
        for (int j = A; j <= B; j++) {
            sum[row][j] += 1;
        }
    }

    int ans = 0;

    for (int i = 1; i <= 366; i++) {
        ans = max(ans, 2 * min(sum[0][i], sum[1][i]));        
    }

    cout << ans << "\n";
    
    return 0;
}
