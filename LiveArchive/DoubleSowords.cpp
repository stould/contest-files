#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef pair<int,int> ii;

const int MAXN = 100010;

int T, N;
int A[MAXN], B[MAXN], C[MAXN];

int main() {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;
    
		set<int> in;
		vector<pair<int, pair<int, char> > > E;
		vector<pair<int, int> > rep_search;

		int ans = 0;
		
		for (int i = 0; i < N; i++) {      
			cin >> A[i] >> B[i] >> C[i];			

			in.insert(A[i]);
			rep_search.push_back(make_pair(A[i], i));
		}

		sort(rep_search.begin(), rep_search.end());
		
		for (int i = 0; i < N; i++) {   
			int l = 0, h = N - 1, m;
			int leastA = N, leastB = -1;
			
			while (l <= h) {
				m = (l + h) / 2;
				
				if (rep_search[m].first >= B[i]) {
					leastA = min(leastA, m);
					h = m - 1;
				} else {
					l = m + 1;
				}
			}
			l = 0, h = N - 1;
			
			while (l <= h) {
				m = (l + h) / 2;
				
				if (rep_search[m].first <= C[i]) {
					leastB = max(leastB, m);
					l = m + 1;
				} else {
					h = m - 1;
				}
			}
			//cerr << leastA << " " << leastB << " => " << B[i] << " " << C[i] << endl;							
			if (leastA == N or leastB == -1) {
				//cerr << B[i] << " " << C[i] << endl;							
				//cerr << rep_search[least].first << " " << B[i] << " " << C[i] << endl;							
				E.push_back(make_pair(B[i], make_pair(i, 'I')));
				E.push_back(make_pair(C[i], make_pair(i, 'O')));			
			} else {
				//cout << "in " << i << " " << leastA << " = " << leastB << " => " << rep_search[leastA].first << " " << rep_search[leastB].first << endl;
				if ((rep_search[leastA].second == i && leastA == leastB) or (rep_search[leastA].second == i && rep_search[leastA].first == A[i])) {
					//cerr << B[i] << " " << C[i] << endl;							
					E.push_back(make_pair(B[i], make_pair(i, 'I')));
					E.push_back(make_pair(C[i], make_pair(i, 'O')));			
				}			
			}
		}

		sort(E.begin(), E.end());
    
		set<int> buff, clear;

		for (int i = 0; i < (int) E.size(); i++) {
			if (clear.count(E[i].second.first)) continue;

			if (E[i].second.second == 'O') {
				ans += 1;
				clear.insert(buff.begin(), buff.end());
				buff.clear();
			} else {
				buff.insert(E[i].second.first);
			}
		}
		
		printf("Case #%d: %d\n", t, ans + (int) in.size());
	}
	
	return 0;
}
