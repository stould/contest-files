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

string A, B;

vector<pair<char, int> > func(string& arg) {
    vector<pair<char, int> > ans;

    for (int i = 0; i < (int) arg.size(); i++) {
        int j = i + 1;
        int cnt = 0;
        
        while (j < (int) arg.size() && arg[j] == arg[j - 1]) {
            cnt += 1;
            j += 1;
        }

        ans.push_back({arg[i], cnt});
        
        i = j - 1;
    }
    
    return ans;
}

int main(void) {
    cin >> A >> B;

    vector<pair<char, int> > sa = func(A);
    vector<pair<char, int> > sb = func(B);

    int ans = 1;

    if (sa.size() == sb.size()) {
        for (int i = 0; i < (int) sa.size(); i++) {
            //cout << sa[i].first << " " << sa[i].second << " = " << sb[i].first << " " << sb[i].second << "\n";
            if (sa[i].first != sb[i].first) {
                ans = 0;
            } else {
                if (sa[i].second > sb[i].second) {
                    ans = 0;
                }
            }
            if (!ans) break;
        }
    } else {
        ans = 0;
    }
    
    cout << ans << "\n";
    
    return 0;
}
