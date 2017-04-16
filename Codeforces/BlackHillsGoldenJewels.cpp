#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int N;
long long K;
long long A[MAXN];

void brute() {
    vector<int> vs, es;
    for (int i = 0; i < N; i++ ){
        for (int j = i + 1; j < N; j++) {
            vs.push_back(A[i] + A[j]);
            es.push_back(A[i] + A[j]);
        }
    }
    sort(vs.begin(), vs.end());

    for (int i = 0; i < (int) vs.size(); i++) {
        cout << vs[i] << " "<< es[i] << "\n";
    }
}

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A, A + N);
    
    long long l = 0, h = 100000000000LL;
    long long ans = 0;
    
    while (l <= h) {
        long long m = (l + h) / 2;

        long long cnt = 0;

        for (int i = 0; i < N; i++) {
            int al = i + 1, ah = N - 1;
            int curr = i;

            while (al <= ah) {
                int am = (al + ah) / 2;
                if (A[i] + A[am] < m) {
                    curr = am;
                    al = am + 1;
                } else {
                    ah = am - 1;
                }
            }
            cnt += curr - i;
        }        
        //cout << m << " " << cnt << "\n";
        if (cnt < K) {
            l = m + 1;
            ans = m;
        } else {
            h = m - 1;
        }
    }
    
    cout << ans << "\n";

    return 0;
}
