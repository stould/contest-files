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

int T;
string S;

int grundy(string arg) {
    if (arg.empty()) return 0;

    int ans = 0;
    set<int> cnt;

    for (int i = 0; i < (int) arg.size(); i++) {
        int s = 0;
        string next = "";
        
        for (int j = 0; j < (int) arg.size(); j++) {
            if (i == j) continue;
            s += arg[j] - '0';
            next += arg[j];
        }

        if (s % 3 == 0 || next.empty()) {
            cnt.insert(grundy(next));
        }
    }

    while (cnt.count(ans)) ans += 1;
    
    return ans;
}

/*
  winner has 0, 2, 5 or 8 as digit
 */
int main(void) {
    for (int i = 100; i <= 120; i++) {
        if (grundy(to_string(i)) != grundy(to_string(i - 1))) {
            //cout << i << " " << grundy(to_string(i)) << "\n";
        }
        int all = 0;
        int px = i;
        while (px > 0) {
            all += px % 10;
            px /= 10;
        }
        if (grundy(to_string(i)) > 0) {
            cout << i << " " << grundy(to_string(i)) << "\n";
        }
    }
    if (S.size() == 2) {
        cout << "T\n";
    } else {

    }
    return 0;
}
