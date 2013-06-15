#include <iostream>
#include <vector>
#include <math.h>
#include <cstdio>

using namespace std;

const int INF = 1000000;

bool vis[10000];
int dist[10000];
int maze[10000][10000];

int dijkstra(int start, int end, int N) {
	dist[start] = 0;
	while (1) {
		int close = -1;

		for (int i = 0; i < N; i++) {
			if (!vis[i] && (close == -1 || dist[i] < dist[close])) {
				close = i;
			}
		}
		if (close == -1) {
			break;
		}

		vis[close] = true;

		for (int i = 0; i < N; i++) {
			int nova = dist[close] + maze[close][i];
			if (nova < dist[i]) {
				dist[i] = nova;
			}
		}
	}
	return dist[end];
}

int main() {
	int to, cost, tests, cities, index, connections, paths;
	int i, j, _cities;
	scanf("%d", &tests);

	while (tests > 0) {
		scanf("%d", &cities);
		_cities = cities;
		vector<string> memo(cities);
		for (i = 0; i < cities; i++) {
			for (j = 0; j < cities; j++) {
				maze[i][j] = INF;
			}
		}
		index = 0;
		while (cities > 0) {
			cin >> memo[index];
			scanf("%d", &connections);
			while (connections > 0) {
				scanf("%d %d", &to, &cost);
				to -= 1;
				maze[index][to] = cost;
				connections--;
			}
			index++;
			cities--;
		}
		scanf("%d", &paths);
		string from, go;
		while (paths > 0) {
			int ifrom, ito;
			cin >> from >> go;
			for (i = 0; i < memo.size(); i++) {
				if (memo[i] == from)
					ifrom = i;
				if (memo[i] == go)
					ito = i;
			}
			for (i = 0; i < _cities; i++) {
				vis[i] = false;
				dist[i] = INF;
			}
			printf("%d\n", dijkstra(ifrom, ito, _cities));
			paths--;
		}
		tests--;
	}
	return 0;
}
