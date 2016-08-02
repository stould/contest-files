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

const int MAXN = 2020;

int N;
string S;
string MEM[MAXN];

int main(void) {
    cin >> S;

    N = (int) S.size();
    vector<int> op, ed;
    
    for (int i = 0; i < N; i++) {
        if (S[i] == '[') {
            op.push_back(i);
            MEM[i] = "";
        } else if (S[i] == ']') {
            ed.push_back(i);
            MEM[i] = "";
        }
    }

    int rdO = 0;
    int lastB = 0;

    bool wrong = false;
    
    for (int i = 0; i < N; i++) {
        if (S[i] == '(') {
            rdO += 1;
        } else if (S[i] == ')') {
            if (rdO > 0) {
                rdO -= 1;
            } else {
                //cout << i << " " << lastB << " " << op.size() << endl;
                if (lastB >= (int) op.size() || op[lastB] > i) {
                    wrong = true;
                    break;
                } else {
                    MEM[op[lastB]] += "(";
                    //rdO += 1;
                }
            }
        }
        if (lastB + 1 < (int) op.size() && op[lastB + 1] == i) {
            lastB += 1;
        }
    }

    while (rdO > 0) {
        if (!ed.empty()) {
            MEM[ed.back()] += ")";
        } else {
            wrong = true;            
        }
        rdO -= 1;
    }    
    
    if (wrong) {
        cout << "Impossible\n";
    } else {
        for (int i = 0; i < N; i++) {
            if (S[i] == '[' || S[i] == ']') {
                cout << MEM[i];
            } else {
                cout << S[i];
            }
        }
        cout << "\n";
    }
    
    return 0;
}
