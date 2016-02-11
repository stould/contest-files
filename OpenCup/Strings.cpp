#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20005;

string A, B;
int K;

int lcp[MAXN];
int str[MAXN]; //input
int rnk[MAXN], pos[MAXN]; //output
int cnt[MAXN], nxt[MAXN]; //internal
bool bh[MAXN], b2h[MAXN];

bool smaller_first_char(int a, int b){
    return str[a] < str[b];
}

void SuffixSort(int n){
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
        if (buckets == n) break; // We are done! Lucky bastards!
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

void getLcp(int n){
    for (int i=0; i<n; ++i) rnk[pos[i]] = i;
    lcp[0] = 0;
    for (int i=0, h=0; i<n; ++i){
        if (rnk[i] > 0){
            int j = pos[rnk[i]-1];
            while (i + h < n && j + h < n && str[i+h] == str[j+h]) h++;
            lcp[rnk[i]] = h;
            if (h > 0) h--;
        }
    }
}

int main(void) {
	//freopen("strings.in", "r", stdin);
	//freopen("strings.out", "w", stdout);
  
	while (cin >> A >> B >> K) {  
		string S = A + "$" + B;

		const int N = (int) S.size();
  
		for (int i = 0; i < N; i++) {
			str[i] = S[i];
		}
  
		SuffixSort(N);
		getLcp(N);
    
		//vector<string> vs;
  
		/*  for (int i = 0; i < N; i++) {
			vs.push_back(S.substr(i, N - i));
			}

			sort(vs.begin(), vs.end());


			for (int i = 0; i < N; i++) {
			cout << lcp[i] << " " << vs[i] << "\n";
			}
		*/

		long long ans = 0LL;
    
		for (int i = 1; i < N; i++) {    
			int cnt = 0;
			int j = i;
			bool valid = false;
			int best = lcp[i];

			if (pos[i - 1] < (int) A.size()) {
				valid = true;
			} else {
				cnt += 1;
			}
      
			while (j < N && lcp[j] > 0) {
				best = min(best, lcp[j]);
				if (pos[j] < A.size()) {
					valid = true;
				} else {
					cnt += 1;
				}      
				j += 1;
			}

			if (valid) {
				//cout << "serr " << lcp[i] << " " << cnt << " " << vs[i] << "\n";
				if (cnt == K) {
					ans += best;
				}
			}
    
			i = j;
		}

		cout << ans << "\n";
	}
  
	return 0;
}
