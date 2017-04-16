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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

string S;

int main(void) {
    cin >> S;

    int ans = 0;
    int carry = 0;
    
    while (!S.empty() && S != "1") {
        
        if (S.back() == '1') {
            carry = 1;
            ans += 1;
            
            while (!S.empty()) {
                if (carry == 0) break;
                
                int now = (S.back() - '0') + carry;
                
                S[S.size() - 1] = char('0' + (now % 2));

                if (now == 2) {
                    carry = 1;
                } else {
                    carry = 0;
                }
                
                if (S.back() == '0') {           
                    S.pop_back();
                } else {
                    break;
                }
                ans += 1;
            }
        } else {
            ans += 1;
            S.pop_back();
        }
    }

    cout << ans << endl;
    
    return 0;
}
