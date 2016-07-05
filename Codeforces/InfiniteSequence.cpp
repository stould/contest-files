

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

Int A, B, C;

int main(void) {
    cin >> A >> B >> C;

    if (A == B) {
        cout << "YES\n";
        return 0;
    }
    
    if (C == 0) {
        if (A == B) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else {
        Int mod = (((B - A) % C) + C) % C;
        
        if (mod == 0 && (B - A) / C >= 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
