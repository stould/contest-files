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
string S;

bool win(string arg) {
    bool ok = false;
    for (int i = 0; i < (int) arg.size() - 2; i++) {
        int cnt = 0;
        for (int j = 0; j < 3; j++) {
            if (arg[i + j] == 'X') {
                cnt += 1;                
            }
        }
        if (cnt >= 2) {
            ok = true;
        }
    }
    if (ok) {
        return 1;
    } else {
        for (int i = 0; i < (int) arg.size(); i++) {
            if (arg[i] == '.') {
                string next = arg;
                next[i] = 'X';

                if (!win(next)) {
                    return 1;
                }
            }
        }
        
        return 0;
    }
}

int main(void) {
    int n = 4;

    for (int i = 0; i < (1 << n); i++) {
        string arg = "";

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                arg += "X";
            } else {
                arg += ".";
            }
        }

        if (!win(arg)) {
            bool ok = false;
            for (int j = 0; j < (int) arg.size() - 2; j++) {
                int cnt = 0;
                for (int k = 0; k < 3; k++) {
                    if (arg[j + k] == 'X') {
                        cnt += 1;                
                    }
                }
                if (cnt == 3) {
                    ok = true;
                }
            }
            if (!ok) {
                cout << arg << "\n";
            }
        }
    }
    /*    while (cin >> N && N != 0) {
        cin >> S;
    }
    */
    return 0;
}
