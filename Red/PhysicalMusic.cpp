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

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 100005;

int T, N;
int P[MAXN];

int main(void) {
    cin >> T;

    while (T--) {
        cin >> N;

        set<int> st;
        
        for (int i = 1; i <= N; i++) {
            cin >> P[i];
        }
        
        for (int i = N; i >= 1; i--) {
            if (P[i] < i) {
                st.insert(i);
            }            
        }

        cout << st.size() << endl;

        for (set<int>::iterator it = st.begin(); it != st.end(); it++) {
            cout << *it << endl;
        }
    }
    return 0;
}
