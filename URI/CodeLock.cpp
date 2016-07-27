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

const int INF = INT_MAX / 3;

string S;
int N;
int dp[1010][80];

int forward(char aa, char bb) {
    int a = aa - 'a';
    int b = bb - 'a';
	
    if (b >= a) {
        return b - a;
    } else {
        return ((26 - a) + b);
    }
}

int backward(char aa, char bb) {
    int a = aa - 'a';
    int b = bb - 'a';

    if (b <= a) {
        return a - b;
    } else {
        return (a + (26 - b));
    }
}

int func(int pos, int fm) {
    if (pos == N) {
        return 0;
    } else {
        int& ans = dp[pos][fm + 26];

        if (ans == -1) {
            ans = INF;
            
            for (int i = 0; i < 26; i++) {
                char currF = 'a' + (fm + i) % 26;
                char currB = 'a' + (((fm - i) % 26) + 26) % 26;
                
                int f = forward(currF, S[pos]);
                int b = backward(currB, S[pos]);

                int uf = fm;
                int lf = fm;
                
                while (uf >= 0) {
                    chmin(ans, i + f + func(pos + 1, uf));
                    uf -= 1;
                }                
                while (lf <= 0) {
                    chmin(ans, i + b + func(pos + 1, lf));
                    lf += 1;
                }
                
                chmin(ans, i + f + func(pos + 1, (fm + i) % 26));
                
                chmin(ans, i + f + func(pos + 1, fm));
                chmin(ans, i + f + func(pos + 1, 0));
                
                chmin(ans, i + b + func(pos + 1, (fm - i + 26) % 26));                                                           
                
                chmin(ans, i + b + func(pos + 1, fm));                
                chmin(ans, i + b + func(pos + 1, 0));                
            }
            /*
            for (int i = fm; i >= 0; i--) {
                char currF = 'a' + (i % 26);

                int f = forward(currF, S[pos]);

                chmin(ans, f - i + func(pos + 1, i));
            }
            for (int i = fm; i <= 0; i++) {
                char currB = 'a' + (fm - i) % 26;

                int b = forward(currB, S[pos]);
                
                //chmin(ans, b - i + func(pos + 1, i));
            }
            */
        }

        return ans;
    }
}

int main(void) {
    while (cin >> S && S != "*") {
        memset(dp, -1, sizeof(dp));
        N = (int) S.size();
        cout << func(0, 0) << "\n";
    }
    
    return 0;
}
