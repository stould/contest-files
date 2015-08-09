#include <bits/stdc++.h>

using namespace std;

int N, M, K;

int main() {
    while (cin >> N >> M >> K) {
       
        if ((N + M) / 3 + (((N + M) % 3) == 0 ? 0 : 1) > K) {
            cout << "-1\n";
        } else {
            int ins = 0;            
            int left = 0;
            
            if (M + N / 3 + ((N % 3 == 0) ? 0 : 1) > K) {            
                if ((N % 3) != 0 && M > 0) {                
                    ins += 1;                
                    M -= 1;  
                    if (N % 3 != 2) {
                        left += 1;
                    } 
                }
                
                K -= N / 3;
                K -= ((N % 3) == 0) ? 0 : 1;

                if (M > K) {
                    if (left) {
                        ins += 1;
                        M -= 1;
                    }
                    ins += (M - K);                
                    ins += (M - K) / 2;
                    
                    ins += (M - K) % 2;         
                }
            }            
            
            cout << ins << "\n";
        }
    }    
    return 0;
}
