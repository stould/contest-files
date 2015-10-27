#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int n,m, test = 1;
vector<vector<pair<int,int> > > g(1001); // first - node, sec - time
int te,a,b,c;
int dist[1001];
bool vis[1001];

void dfs(int u){
	vis[u] = 1;
	for(int i = 0; i < g[u].size(); i++){
		int next = g[u][i].first;
		if(!vis[next]){
			dfs(next);
		}
	}
}

bool bellman(){
	for(int i = 0; i < n-1; i++){
		for(int u = 0; u < n; u++){
			for(int j = 0; j < g[u].size(); j++){
				pair<int,int> v = g[u][j];
				dist[v.first] = min(dist[v.first], dist[u] + v.second);
			}
		}
	}
	bool ans = 0;
	for(int u = 0; u < n && !ans; u++){
		for(int j = 0; j < g[u].size() && !ans; j++){
			pair<int,int> v = g[u][j];
			if(dist[v.first] > dist[u] + v.second){
				dfs(u);
				if(vis[0]) ans=1;
			}
		}
	}
	return ans;
}





int main(void) {

	cin >> te;

	for(int t=1; t<=te; t++) {
		cin >> n >> m;

		for(int i = 0; i < 1001; i++) {
			g[i].clear();
			dist[i] = INF;
			vis[i] = 0;
		}
    
		for(int i=0; i<m; i++) {
			cin >> a >> b >> c;
			g[a].push_back(make_pair(b, c));
		}
		if(bellman()){
			cout << "Case #" << test++ << ": possible" << endl;
		}else{
			cout << "Case #" << test++ << ": not possible" << endl;
		}
	}

	return 0;
}
