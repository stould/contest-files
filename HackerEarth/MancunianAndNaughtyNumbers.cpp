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

const int MAXN = 1000005;

int Q;
int sum[MAXN];
int p[MAXN], bef[MAXN];

void build() {
    for (int i = 2; i < MAXN; i++) {
        if (!p[i]) {
            for (int j = i; j < MAXN; j += i) {
                bef[j] = i;
                p[j] = true;
            }
        }
    }
}

int factors(int x) {
    set<int> st;
    
    while (x > 1) {
        st.insert(bef[x]);
        x /= bef[x];
    }
    
    return st.size();
}

int digits(int x) {
    if (x == 0) return 1;
    int ans = 0;

    while (x > 0) {
        ans += 1;
        x /= 10;
    }

    return ans;
}

int main(void) {
    cin >> Q;

    build();

    sum[1] = 1;
    
    for (int i = 2; i < MAXN; i++) {
        sum[i] = sum[i - 1] + (digits(i) == factors(i));
    }
    
    while (Q--) {
        int a, b;
        cin >> a >> b;

        cout << sum[b] - sum[a - 1] << "\n";
    }
    return 0;
}
