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
 
const int MAXN = 1005;
 
int N, M;
int F[MAXN], cnt[MAXN];
vector<int> MI;
 
int func(int val) {
    int l = 0, h = MI.size() - 1, m;
    int best = -1;
 
    while (l <= h) {
        m = (l + h) / 2;
 
        if (MI[m] <= val) {
            best = max(best, m);
            l = m + 1;
        } else {
            h = m - 1;
        }       
    }
 
    if (best == -1) best = MI.size() - 1;
     
    return best;
}
 
int main(void) {
    while (cin >> N >> M) {
        MI = vector<int>(N);
		memset(cnt, 0, sizeof(cnt));
		
        for (int i = 0; i < N; i++) {
            cin >> MI[i];
			cnt[MI[i]] += 1;
        }
 
        sort(MI.begin(), MI.end());
         
        for (int i = 0; i < M; i++) {
            cin >> F[i];
        }
         
        for (int i = 0; i < M; i++) {
            if (MI.empty()) break;
             
            int best = func(F[i]);

			cnt[MI[best]] -= 1;
            MI[best] = max(0, MI[best] - F[i]);
			
            if (MI[best] == 0) {
                MI.erase(MI.begin() + best);
            } else {
				cnt[MI[best]] += 1;
				
				MI.clear();

				for (int j = 1; j < MAXN; j++) {
					for (int k = 0; k < cnt[j]; k++) {
						MI.push_back(j);
					}
				}
            }
        }
 
        int ans = N - MI.size();
 
        cout << ans << endl;
    }
    return 0;
}
