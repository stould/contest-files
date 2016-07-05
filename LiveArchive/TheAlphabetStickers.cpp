#include <bits/stdc++.h>

using namespace std;

typedef long long Int;

const Int MOD = 1000000007LL;

int T, N;
string S;

int main() {
    cin >> T;
    
    while (T--) {
        cin >> S;

        int N = (int) S.size();
        
        Int ans = 1LL;
        
        for (int i = 0; i < N; i++) {
           if (S[i] == '?') {
                int j = i;
                
                while (j < N && S[j] == '?') {
                    j += 1;
                }
                
                char a = '$';
                char b = '$';
                
                if (i - 1 >= 0) a = S[i - 1];
                if (j != N) b = S[j];                
                
                if (a != '$' && b != '$' && a != b) {
                    ans *= (Int) (j - i + 1);
                    ans %= MOD;
                }       
                            
                i = j - 1;
           }
        }
        
        cout << ans <<"\n";
    }
    return 0;
}
