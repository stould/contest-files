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

int main(void) {
    int N = 2000;
    vector<int> seen(N + 1, 1);

    seen[0] = 1;
    seen[1] = 1;
    
    for (int i = 2; i <= N; i++) {
        seen[i] = seen[i - 1] + seen[i - 2];

        if (seen[i] > N) break;
        cout << seen[i] << endl;
    }
    return 0;
}
