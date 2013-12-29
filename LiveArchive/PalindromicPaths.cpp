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

int T;
int N;

char str[60][60];

string dp[60][60];
bool mark[60][60];

string func(int a, int b) {
    if (a > b) {
        return "$";
    } else if (a + 1 == b) {
        return string(1, str[a][b]);
    } else if (a == b) {
        return "";        
    } else {
        string& ans = dp[a][b];

        if (!mark[a][b]) {
            mark[a][b] = true;
            
            int i;
            int j;

            ans = "";

            for (i = a; i <= b; i++) {
                for (j = b; j >= a; j--) {        
                    if (str[a][i] == str[b][j] && str[a][i] != '*') {
                        string curr = "";                       
                      
                        if (i == b) {
                            curr = string(1, str[a][b]);
                        } else {
                            curr = str[a][i] + func(i, j) + str[b][j];                                                    
                        }
                    
                        if (curr.find("$") != string::npos) continue;

                        if (curr.size() > ans.size() || (curr.size() == ans.size() && curr < ans)) {  
                            ans = curr;
                        }
                    }
                }
            }
        }

        return ans;
    }
}

int main(void) {
    T = in();

    int i;

    for ( ; T--; ) {
        N = in();

        for (i = 0; i < N; i++) {
            scanf("%s", str[i]);
        }

        memset(mark, false, sizeof(mark));

        
        string ans = func(0, N - 1);

        puts(ans.c_str());
    }

    return 0;
}