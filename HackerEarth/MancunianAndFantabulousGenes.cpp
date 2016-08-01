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

const int MAXN = 100005;

int N, K;
string S;
int sum[MAXN][30];

string preProcess(string s) {
    int n = (int) s.length();
    if (n == 0) return "^$";
    string ret = "^";

    for (int i = 0; i < n; i++) {
        ret += "#" + s.substr(i, 1);
    }
    
    ret += "#$";
    return ret;
}
 
vector<int> manacher(string s) {
    string T = preProcess(s);
    int n = (int) T.length();
    vector<int> P(n);

    int C = 0, R = 0;
    for (int i = 1; i < n-1; i++) {
        int i_mirror = 2*C-i;
	  
        P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
	  
        while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
            P[i]++;
        }
 
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }
  
    //to return actual longets substring
    //  return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
    // P[i] is the length of the largest palindrome centered at i
    return P;
}


int main(void) {
    cin >> N >> K >> S;

    Int ans = 0;
    
    string nova = preProcess(S);
    vector<int> P = manacher(S);
    cout << nova << "\n";

    for (int i = 2; i < (int) P.size() - 2; i++) {
        if (i % 2 == 0) {
            sum[i][nova[i] - 'a'] += 1;
        }       
        for (int j = 0; j < 26; j++) {
            sum[i][j] += sum[i - 1][j];
        }        
    }
    
    for (int i = 0; i < (int) P.size() - 2; i++) {
        //cout << P[i] << " ";
        if (P[i] > 0) {           
            if (i % 2 == 0) {
                int l = 1, h = P[i];
                int best = 0;
                
                while (l <= h) {
                    int m = (l + h) / 2;

                    vector<int> s1(26);

                    for (int j = 0; j < 26; j++) {
                        s1[j] += sum[i + m / 2][j];
                        s1[j] -= sum[i -  m / 2][j];
                    }

                    Int cnt = 0;
                    
                    for (int j = 0; j < 26; j++) {
                        if (s1[j] > 0) {
                            cnt += 1;
                        }
                    }
                    cout << i << " " << m << " " << cnt * (1 + m) << "\n";
                    if (cnt * (1 + m) < K) {
                        l = m + 1;
                    } else {
                        
                        best = m;
                        h = m - 1;
                    }
                }
                //cout << best << "\n";
                ans += P[i] - best;
            }
        }
    }
    cout <<" \n";

    cout << ans << "\n";
    return 0;
}
