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

const int MAXN = 1000005;

int T, A, B;
int sum[MAXN];
int tot[MAXN];

bool isPal(string& arg) {
    for (int i = 0; i < (int) arg.size() / 2; i++) {
        if (arg[i] != arg[(int) arg.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

int func(int x) {
    string dec = "";
    string bin = "";

    int buff = x;

    while (buff > 0) {
        dec = dec + char('0' + buff % 10);
        buff /= 10;
    }

    if (isPal(dec)) {    
        buff = x;
        
        while (buff > 0) {
            bin = bin + char('0' + buff % 2);
            buff /= 2;
        }

        if (isPal(bin)) {
            return 1;
        } else {
            return 0;
        }
            
    } else {
        return 0;
    }
}

int main(void) {
    for (int i = 1; i < MAXN; i++) {
        sum[i] = sum[i - 1];
        tot[i] = tot[i - 1];

        if (func(i)) {
            sum[i] += i;
            tot[i] += 1;
        }
    }
    
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        cin >> A >> B;

        int ss = sum[B] - sum[A - 1];
        int tt = tot[B] - tot[A - 1];
        
        cout << ss << " " << tt << endl;
    }
    return 0;
}
