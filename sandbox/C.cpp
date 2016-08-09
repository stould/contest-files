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

using namespace std;

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 300005;

int N, Q;
int pr[MAXN], all[MAXN];
map<int, int> st;

int main(void) {
    cin >> N >> Q;

    int ans = 0;
    int bg = 0;
    
    for (int i = 1; i <= Q; i++) {
        int type, val;
        
        cin >> type >> val;
        
        if (type == 1) {
            all[i] = val;
            pr[st[val]];
            st[val] = i;
            ans += 1;
        } else if (type == 2) {
            int pos = st[val];

            while (pos > bg) {
                
            }
        } else {
        }

        cout << ans << "\n";
    }
    return 0;
}
