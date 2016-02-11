#include <bits/stdc++.h>
#define ll long long
#define MAXN 1000003
#define INF 10000000
#define mp make_pair

using namespace std;

ll ft[MAXN], cpy[MAXN];
unordered_map<ll, ll> cd;

struct FenwickTree{
 
	int sz;
 
	FenwickTree(int N){
		memset(ft,0,sizeof(ft));
		sz = N;
	}
 
	ll query(int idx){
		ll ans = 0;
		while(idx > 0){
			ans += ft[idx];
			idx -= (idx & -idx);
		}
		return ans;
	}
 
	ll query(int a, int b){
		if(a == 1){
			return query(b);
		}else{
			return query(b) - query(a-1);
		}
	}
 
	void update(int idx, int val){
		while(idx <= sz){
			ft[idx] += val;
			idx += (idx & -idx);
		}
	}
};
 
int n;
ll v[MAXN];

int main(void){
	//freopen("in.in", "r", stdin);
	scanf("%d\n", &n);
	ll ans = 0;
	FenwickTree tree(n+1);
	for(int i = 0; i < n; i++){
		scanf("%lld", &v[i]);
		cpy[i] = v[i];
	}

	sort(cpy, cpy + n);
  
	int id = 1;
  
	for (int i = 0; i < n; i++) {
		if (cd.find(cpy[i]) == cd.end()) cd[cpy[i]] = id++;
	}
  
	for (int i = 0; i < n; i++) {
		v[i] = cd[v[i]];
		ans += i - tree.query(1, (int)v[i]);
		tree.update((int)v[i], 1);
	}
	printf("%lld\n", ans);
	return 0;
}
