#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

ll N, S;
ll v[300001];
bool vis[300001];

int main() {

	cin >> N >> S;
	vector<ll> ans;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v, v+N);
	int lo = 0, hi = N-1;

	while(1){
		while(lo < hi && v[lo] + v[hi] <= S){
			lo++;
		}
		if(lo >= hi) break;
		ans.push_back(v[lo]);

		ans.push_back(v[hi]);
		vis[lo] = vis[hi] = 1;
		lo++;
		hi--;
	}
	vector<ll> ans2;
	for(int i = N-1; i >= 0; i--){
		if(!vis[i]) ans.push_back(v[i]);
	}
	int tot = 0;
	for(int i = 0; i < N;) {
		if(i == N-1) {
			tot++;
			break;
		}
		if(ans[i] - S > -ans[i+1]){
			i++;
		}else{
			i += 2;
		}
		tot++;
	}
	cout << tot << endl;
	for(int i = 0; i < N; i++) cout << ans[i] << " ";
	cout << endl;
  
	return 0;
}
