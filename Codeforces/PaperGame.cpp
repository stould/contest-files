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

int T;
int A, B;

int grundy(int x, int y) {
    if (x == 1 && y == 1) {
        return 0;
    } else {
        int ans = 0;
        set<int> st;

        for (int i = 1; i < x; i++) {
            if (x - i <= 0) break;
            st.insert(grundy(i, y) ^ grundy(x - i, y));
        }
        for (int i = 1; i < y; i++) {
            if (y - i <= 0) break;
            st.insert(grundy(x, i) ^ grundy(x, y - i));
        }
        while (st.count(ans)) ans++;
        return ans;
    }
}

int main(void) {
    cin >> T;
    /*
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            cout << grundy(i, j) << " ";
        }
        cout << "\n";
    }
    */
    for (int t = 1; t <= T; t++) {
        cin >> A >> B;

        if (A % 2 == 0) {
            cout << "Hasan\n";
        } else {
            if (B % 2 == 0) {
                cout << "Hasan\n";
            } else {
                cout << "Hussain\n";
            }
        }
    }
    return 0;
}
