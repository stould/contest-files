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

const int MAXN = 30000006;

int N;
bool is[MAXN];
set<int> primes;

int main(void) {
    cin >> N;

    for (int i = 2; i < MAXN; i++) {
        if (!is[i]) {
            for (Int j = i * (Int) i; j < MAXN; j += i) {
                is[j] = true;
            }
        }
    }

    for (int i = 2; i < MAXN; i++) {
        if (!is[i]) {
            primes.insert(i);
        }
    }

    vector<int> ans;

   
    if (primes.count(N)) {
        ans.push_back(N);
    } else {    
        int other_N = N;
        
        for (set<int>::iterator it = primes.begin(); it != primes.end(); it++) {
            int curr = *it;

            while (other_N % curr == 0) {
                other_N /= curr;
            }

            if (primes.count(N - curr)) {
                ans.push_back(curr);
                ans.push_back(N - curr);
                break;
            }
        
            if ((N - curr) % 2 == 0 && primes.count((N - curr) / 2)) {
                ans.push_back(curr);
                ans.push_back((N - curr) / 2);
                ans.push_back((N - curr) / 2);
                break;
            }
        }
        
        if (ans.empty() && other_N > 1) {
            ans.clear();
            ans.push_back(N);
        }
    }
    cout << ans.size() << "\n";

    for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i] << " ";
    }
    
    cout << "\n";
    
    return 0;
}
