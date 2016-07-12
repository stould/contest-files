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

int main(void) {
    cin >> N;

    int L = 1;

    for (int i = 0; i < N; i++) {
        L *= 2;
    }

    vector<int> op;
    stack<int> c;
    int pos = 1;
    vector<int> P(L);
    
    for (int i = 0; i < L; i++) {
        cin >> P[i];
    }
    
    for (int len = 1; len <= N; len++) {
        for (int i = 0; i < (int) P.size(); i++) {
            op.push_back(P[i]);
            c.push(P[i]);
            
            while (!c.empty() && c.top() == pos) {
                op.push_back(c.top());
                
                for (int j = len + 1; j <= N; j++) {
                    op.push_back(c.top());
                    op.push_back(c.top());
                }
                c.pop();
                pos += 1;
            }
        }
        P.clear();
        while (!c.empty()) {
            P.push_back(c.top());
            op.push_back(c.top());
            c.pop();
        }
    }
    for (int i = 0; i < (int) P.size(); i++) {
        op.push_back(P[i]);
    }
    for (int i = 0; i < (int) op.size(); i++) {
        cout << op[i] << " ";
    }
    cout << "\n";

    return 0;
}
