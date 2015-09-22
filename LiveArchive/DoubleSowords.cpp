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
		map<int, int> cnt;
		
		for (int i = 0; i < N; i++) {      
			cin >> A[i] >> B[i] >> C[i];
			
			cnt[A[i]] += 1;
			in.insert(A[i]);
		}
		
		for (int i = 0; i < N; i++) {   
			set<int>::iterator bound = in.lower_bound(B[i] - 1);

			if (bound == in.end()) {
				bound--;
			}
			//cerr << *bound << " " << B[i] << " " << C[i] << endl;
			//cout << *bound << endl;
			if (bound == in.end() or !(*bound >= B[i] && *bound <= C[i])) {
				//cerr << B[i] << " " << C[i] << endl;
				E.push_back(make_pair(B[i], make_pair(i, 'I')));
				E.push_back(make_pair(C[i], make_pair(i, 'O')));
			}
		}

		sort(E.begin(), E.end());
    
		set<int> buff, clear;
		int ans = 0;

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
