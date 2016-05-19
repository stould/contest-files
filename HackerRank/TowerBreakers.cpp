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

int T, N, M;

int getGrundy(int val) {
    if (val <= 1) return 0;

    set<int> st;
    
    for (int i = 1; i < val; i++) {
        if (val % i == 0) {
            st.insert(getGrundy(i));
        }
    }

    int ans = 0;

    for (int i = 0; ; i++) {
        if (!st.count(i)) {
            ans = i;
            break;
        }
    }

    return ans;
}

int win(int x) {
    if (x == 1) return 0;

    for (int i = 1; i < x; i++) {
        if (x % i == 0 && !win(i)) {
            return 1;
        }
    }
    return 0;
}

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> M;

        if (M == 1) {
            cout << "2" << endl;
        } else {
            if (N % 2 == 0) {
                cout << "2" << endl;
            } else {
                cout << "1" << endl;
            }
        }
    }
    return 0;
}
