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
typedef unsigned uint;

const int MAXN = 100005;

int N;
int P[MAXN];

int main(void) {
    freopen("i.in", "r", stdin);
    cin >> N;

    set<int> ans;
    bool ten = false;
    for (int i = 0; i < N; i++) {
        cin >> P[i];

        if (P[i] == 0 || P[i] == 100) {
            ans.insert(P[i]);
        } else if (P[i] % 10 == 0 && !ten) {
            ten = true;
            ans.insert(P[i]);
        }
    }

    bool A = false, B = false;

    for (int i = 0; i < N; i++) {
        if (P[i] != 0) {
            if (!A && P[i] < 10) {
                A = true;
                ans.insert(P[i]);
            } else if (!B && P[i] > 10 && ans.count(100)) {
                B = true;
                ans.insert(P[i]);
            }
        }
    }

    if (ans.size() == 0) {
        ans.insert(P[0]);
    }

    cout << ans.size() << "\n";

    for (set<int>::iterator it = ans.begin(); it != ans.end(); it++) {
        cout << *it << " ";
    }

    return 0;
}
