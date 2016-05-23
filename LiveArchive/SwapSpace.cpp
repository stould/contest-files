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

using namespace std;

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 1000005;

int N;
Int A[MAXN], B[MAXN];


int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    Int l = 0LL, h = 10000000000LL, m;
    Int ans = 0;

    while (l <= h) {
        m = (l + h) / 2;

        Int curr = m;
        bool valid = true;
        
        vector<pair<Int, Int> > fine;
        vector<pair<Int, Int> > rest;
        
        for (int i = 0; i < N; i++) {
            if (B[i] >= A[i]) {
                fine.push_back(make_pair(A[i], B[i]));
            } else {
                rest.push_back(make_pair(A[i], B[i]));
            }
        }
        
        sort(fine.begin(), fine.end());
        sort(rest.rbegin(), rest.rend());
        
        for (int i = 0; i < (int) fine.size(); i++) {
            Int u = fine[i].first;
            Int q = fine[i].second;
            
            curr -= u;

            if (curr < 0) {
                valid = false;
            }

            curr += q;
        }
        
        for (int i = 0; i < (int) rest.size(); i++) {
            Int u = rest[i].first;
            Int q = rest[i].second;

            curr -= u;
            
            if (curr < 0) {
                valid = false;
            }

            curr += q;            
        }

        if (valid) {
            ans = m;
            h = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << ans << endl;
    
    return 0;
}
