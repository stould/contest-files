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

int N;
Int P[MAXN];

int main(void) {
    cin >> N;

    set<Int> st;
    
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        st.insert(P[i]);                    
    }
    if (st.size() <= 2) {
        cout << "YES\n";
    } else {
        if (st.size() == 3) {
            vector<Int> curr(st.begin(), st.end());
            
            sort(curr.begin(), curr.end());
            
            if (abs(curr[0] - curr[1]) == abs(curr[2] - curr[1])) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
