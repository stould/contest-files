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

int N;
Int P;
int memo[100];

int getGrundy(int x) {
    if (x == 1) {
        return 0;
    } else {
        int& ans = memo[x];

        if (ans != -1) return ans;
        ans = 0;
        
        set<int> st;
        
        for (int i = 1; i < x; i++) {
            st.insert(getGrundy(i) ^ getGrundy(x - i));
        }

        while (st.count(ans)) ans++;

        return ans;
    }
}

int main(void) {
    cin >> N;

    int x = 1;
    
    for (int i = 0; i < N; i++) {
        cin >> P;

        x ^= (P % 2 == 0 ? 1 : 0);

        if (x == 0) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    }
    return 0;
}
