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

const int MAXN = 1100 + 26 * 26 * 26;
const int INF = 10100;

int N, cnt, sum;
string S;
vector<int> graph[MAXN];

void add_edge(int a, int b) {
	//graph[a].push_back(b);
	graph[b].push_back(a);
}

bool bpm(int u, bool seen[], int matchR[]) {
    for (int i = 0; i < (int) graph[u].size(); i++) {
		int v = graph[u][i];

        if (!seen[v]) {
            seen[v] = true; 
 
            if (matchR[v] < 0 || bpm(matchR[v], seen, matchR)) {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}
 
int maxBPM() {
    int matchR[MAXN];
 
    memset(matchR, -1, sizeof(matchR));
	
    int result = 0; 
    for (int u = 1; u < MAXN; u++) {
        bool seen[MAXN];
        memset(seen, 0, sizeof(seen));

        if (bpm(u, seen, matchR)) {
            result++;
		}
    }
    return result;
}


int hash(string s) {
	int L = (int) s.size();

	int base = 1;
	int hash = 0;

	for (int i = L - 1; i >= 0; i--) {
		hash += base * (s[i] - 'a');
		base *= 26;
	}

	return hash;
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;

	sum = 0;
	
	for (int i = 1; i <= N; i++) {
		cin >> cnt >> S;

		sum += cnt;

		int len = (int) S.size();

		for (int j = 0; j < len; j++) {
			for (int k = j + 1; k < len; k++) {
				for (int l = k + 1; l < len; l++) {
					int curr_hash = hash(string(1, S[j]) + string(1, S[k]) + string(1, S[l]));
					
					for (int x = sum - cnt; x < sum; x++) {
						add_edge(x, curr_hash);
					}					
				}
			}
		}
	}

	int ans = maxBPM();

	if (ans == sum) {
		cout << "Possivel\n";
	} else {
		cout << "Impossivel\n";
	}

    return 0;
}
