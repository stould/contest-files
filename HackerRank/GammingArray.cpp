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

int T, N;

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;

        priority_queue<pair<int, int> > q;
        
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;

            q.push(make_pair(x, i));
        }

        int w = 0;
        int best = N + 1;
        
        while (!q.empty()) {
            int c = q.top().second;
            q.pop();

            if (c > best) continue;

            w = (w + 1) % 2;
            best = min(best, c);
            
            if (c == 0) {
                break;
            }
        }

        if (w == 1) {
            cout << "BOB" << endl;
        } else {
            cout << "ANDY" << endl;
        }
    }
    return 0;
}
