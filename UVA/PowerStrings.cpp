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

string S;

vector<int> KMP(string K) {
    vector<int> T(K.size() + 1, -1);
    vector<int> matches;

    if(K.size() == 0) {
        matches.push_back(0);
        return matches;
    }
    for(int i = 1; i <= (int) K.size(); i++) {
        int pos = T[i - 1];
        while(pos != -1 && K[pos] != K[i - 1]) pos = T[pos];
        T[i] = pos + 1;
    }

    return T;
}

//Find string period
int stringPeriod(string arg) {
    int ori_len = (int) arg.size();
    arg = arg + arg;
    
    vector<int> prefix = KMP(arg);
    int ans = (int) arg.size();
    
    for (int i = ori_len; i < (int) prefix.size(); i++) {
        if (prefix[i] >= ori_len) {
            ans = i - prefix[i];
            break;
        }
    }
    return ans;
}

int main(void) {
    while (cin >> S && S != ".") {
        cout << (int) S.size() / stringPeriod(S) <<"\n";
    }
    return 0;
}
