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

const Int INF = 100101010010101010LL;
const int MAXN = 10010;

int N, V;
int ans;
int X[MAXN], Y[MAXN], C[MAXN];
vector<int> graph[MAXN];
bool vis[MAXN];

#define IN getc( stdin )

void fastint( register int *n ){
    register char c;
    *n = 0;
    while(!isdigit((c = IN)));
    ungetc(c, stdin);
    while(c = IN){
        switch( c ){
            case ' ': return;
            case '\n': return;
            default: (*n) *= 10; (*n) += ( c - '0' ); 
        }
    }
}

void dfs(int node, int p) {
	for (int i = 0; i < (int) graph[node].size(); i++) {
		int nxt = graph[node][i];

		if (nxt != p) {
			dfs(nxt, node);
		}
	}

	if (C[node] < V) {
		C[p] += C[node];
	} else {
		ans += 1;
	}

	graph[node].clear();
	
}

int main(void) {
	for ( ; ; ) {
		fastint(&N);
		if (N == 0) break;
		
		fastint(&V);

		
		if (N == 0 && V == 0) {
			break;
		}

		for (int i = 0; i < N; i++) {
			fastint(&X[i]);
			fastint(&Y[i]);
			fastint(&C[i]);

			if (i == 0) continue;
			
			double dst = INF;
			int index = -1;
			
			for (int j = 0; j < i; j++) {
				double curr_dst = (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);

				if (curr_dst < dst) {
					dst = curr_dst;
					index = j;
				}
			}
			graph[index].push_back(i);
		}

		ans = 0;
		dfs(0, -1);
		
		printf("%d\n", ans);
	}
	
    return 0;
}
