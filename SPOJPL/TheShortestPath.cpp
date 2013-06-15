#include <string>
#include <set>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

const int INF = 1000000000;
int test, n, routes, number, cost, queries, dist[10010];
char city[12], from[12], to[12];

int main(void) {
    scanf("%d", &test);
    for(; test-- > 0; ) {
    	scanf("%d", &n);
    	map<string, int> mp;
    	vector<pair<int, int> > graph[n + 1];
    	for(int i = 1; i <= n; i++) {
    		scanf("%s%d", city, &routes);
    		mp[string(city)] = i;
    		for(int j = 0; j < routes; j++) {
    			scanf("%d%d", &number, &cost);
    			graph[i].push_back(make_pair(number, cost));
    		}
    	}
    	scanf("%d", &queries);
    	for(int x = 0; x < queries; x++) {
    		scanf("%s %s", from, to);
    		fill(dist, dist + n + 1, INF);
    		set<int> q;
    		q.insert(mp[string(from)]);
    		dist[mp[string(from)]] = 0;

    		while(!q.empty()) {
    			int tmp = (*q.begin()); q.erase(q.begin());

    			for(int i = 0; i < (int) graph[tmp].size(); i++) {
    				int &actual = dist[graph[tmp][i].first];
    				int next = dist[tmp] + graph[tmp][i].second;

    				if(next < actual) {
    					actual = next;
    					q.insert(graph[tmp][i].first);
    				}
    			}
    		}
    		printf("%d\n", dist[mp[string(to)]]);
    	}
    }
	return 0;
}

