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

const int MAXN = 1000006;
const int INF = INT_MAX / 3;

int N, SN;
string S, P[155];

// O(n log n) - Manber and Myers algorithm

int str[MAXN]; 
int rnk[MAXN], pos[MAXN]; 
int cnt[MAXN], nxt[MAXN]; 
bool bh[MAXN], b2h[MAXN];

bool smaller_first_char(int a, int b){
    return str[a] < str[b];
}

void suffixSort(int n){
    for (int i=0; i<n; ++i){
        pos[i] = i;
    }

    sort(pos, pos + n, smaller_first_char);

    for (int i=0; i<n; ++i){
        bh[i] = i == 0 || str[pos[i]] != str[pos[i-1]];
        b2h[i] = false;
    }

    for (int h = 1; h < n; h <<= 1){
        int buckets = 0;
        for (int i=0, j; i < n; i = j){
            j = i + 1;
            while (j < n && !bh[j]) j++;
            nxt[i] = j;
            buckets++;
        }
        if (buckets == n) break; 

        for (int i = 0; i < n; i = nxt[i]){
            cnt[i] = 0;
            for (int j = i; j < nxt[i]; ++j){
                rnk[pos[j]] = i;
            }
        }

        cnt[rnk[n - h]]++;
        b2h[rnk[n - h]] = true;
        for (int i = 0; i < n; i = nxt[i]){
            for (int j = i; j < nxt[i]; ++j){
                int s = pos[j] - h;
                if (s >= 0){
                    int head = rnk[s];
                    rnk[s] = head + cnt[head]++;
                    b2h[rnk[s]] = true;
                }
            }
            for (int j = i; j < nxt[i]; ++j){
                int s = pos[j] - h;
                if (s >= 0 && b2h[rnk[s]]){
                    for (int k = rnk[s]+1; !bh[k] && b2h[k]; k++) b2h[k] = false;
                }
            }
        }
        for (int i=0; i<n; ++i){
            pos[rnk[i]] = i;
            bh[i] |= b2h[i];
        }
    }
    for (int i=0; i<n; ++i){
        rnk[pos[i]] = i;
    }
}

int lower_bound_search(string s) {
	int l = 0, h = SN, m;
	int M = (int) s.size();
	int ans = INF;

	for ( ; l <= h; ) {
		m = (l + h) / 2;

		string curr = S.substr(pos[m], min(M, SN - pos[m]));
		
		if (curr == s) {
			chmin(ans, m);
			h = m - 1;
		} else if (curr < s) {
			l = m + 1;
		} else {
			h = m - 1;
		}
	}
	return ans;
}

int upper_bound_search(string s) {
	int l = 0, h = SN - 1, m;
	int M = (int) s.size();
	int ans = -INF;

	for ( ; l <= h; ) {
		m = (l + h) / 2;

		string curr = S.substr(pos[m], min(M, SN - pos[m]));

		if (curr == s) {
			chmax(ans, m);
			l = m + 1;
		} else if (curr < s) {
			l = m + 1;
		} else {
			h = m - 1;
		}
	}
	return ans;
}

int occur(string s) {
	int l = lower_bound_search(s);
	int h = upper_bound_search(s);	

	if (l != INF) {
		return h - l + 1;
	} else {
		return 0;
	}
}

int main(void) {
	for ( ; cin >> N && N != 0; ) {
		for (int i = 0; i < N; i++) {
			cin >> P[i];
		}
		cin >> S;

		SN = (int) S.size();

		for (int i = 0; i < SN; i++) {
			str[i] = S[i];
		}

		suffixSort(SN);

		vector<int> ans;		
		int best = 0;
		
		for (int i = 0; i < N; i++) {
			int curr = occur(P[i]);

			if (curr > best) {
				ans.clear();
				ans.push_back(i);
				best = curr;
			} else if (curr == best && best != 0) {
				ans.push_back(i);
			}
		}

		cout << best << "\n";

		for (int i = 0; i < (int) ans.size(); i++) {
			cout << P[i] << "\n";
		}
	}
    return 0;
}
