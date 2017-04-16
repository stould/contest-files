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

Int val;
Int sum;

int main(void) {
    int in = 1;
    sum = 0;
    
    while (cin >> val && val != 0) {
        sum += val;
        
        if (sum >= 100) {
            cout << "Input #" << in << ": Totally Sweet!" << endl;;
            sum %= 50;
        } else if (sum >= 50) {
            cout << "Input #" << in << ": Sweet!" << endl;;
            sum %= 50;
        }
        in += 1;
    }
    return 0;
}
