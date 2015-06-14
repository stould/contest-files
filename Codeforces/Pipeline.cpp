#include <iostream>
#include <string>
#include <cstring>

using namespace std;

typedef long long Int;

Int N, K;

Int sumF(Int p) {
    return p * (K + (K - p + 1)) / 2LL;
}

int main(void) {
    cin >> N >> K;
    
    if (N == 1) {
        cout << "0\n";
        return 0;
    }
    
    Int l = 1, h = K, m;
    Int ans = 10010101001010LL;
    
    for ( ; l <= h; ) {
        m = (l + h) / 2;
        
        Int sum = sumF(m) - m + 1;
        
//        cerr << sum << " - " << m << "\n";
        
        if (sum == N) {
            ans = min(ans, m);
            break;
        } else if (sum < N) {
            if (N - sum <= K - m - 1) {
//                cerr << "fit\n";
                ans = min(ans, m + 1);
            }
            l = m + 1;            
        } else {
            if (sum - N <= K - m - 1) {
//                cerr << "fit\n";
                ans = min(ans, m + 1);
            } 
            h = m - 1;            
        }
    }       
    if (ans >= 10010101001010LL) {
        ans = -1;
    }
    cout << ans << "\n";
    
    return 0;
}
