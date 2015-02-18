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

const int MAXN = 100005;

int N, M;
string S[MAXN], P[MAXN], Q[MAXN];
int cR[MAXN];
bool vis[MAXN];

int hash_id = 1;
unordered_map<string, int> hsh;

vector<int> graph[MAXN];

struct data {
	string value;
	int r;
	int id;

	data(){}

	data(string value, int r, int id): 
		value(value),
		r(r),
		id(id) {}

	bool operator<(const data& other) const {
		if (r != other.r) {
			return r < other.r;
		} else {
			return value.size() < other.value.size();
		}
	}
};

data store[MAXN], best[MAXN];

void fix(string& s) {
	int r = 0;

	for (int i = 0; i < (int) s.size(); i++) {
		s[i] = tolower(s[i]);
		if (s[i] == 'r') r += 1;
	}

	if (hsh[s] <= 0) {
		hsh[s] = hash_id++;
	}

	store[hsh[s]] = data(s, r, hsh[s]);
	best[hsh[s]] = store[hsh[s]];
}

void dfs(int h, data aux) {
	if (vis[h]) return;	
	vis[h] = true;
	best[h] = aux;

	for (const auto& i: graph[h]) {
		dfs(i, aux);		
	}
}

pair<int, int> seek(int h) {
	pair<int, int> ans = make_pair(best[h].r, (int) best[h].value.size());
	return ans;
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> S[i];
		fix(S[i]);
    }
    
    cin >> M;

    for (int i = 0; i < M; i++) {
        cin >> P[i] >> Q[i];

		fix(P[i]);
		fix(Q[i]);

		graph[hsh[Q[i]]].push_back(hsh[P[i]]);
    }

	sort(store + 1, store + hash_id);

	for (int i = 1; i < hash_id; i++) {
		dfs(store[i].id, store[i]);
	}	

    Int len = 0, r = 0;

	for (int i = 0; i < N; i++) {
		pair<int, int> now = seek(hsh[S[i]]);
		
		r += now.first;
		len += (Int) now.second;			
	}

    cout << r << " " << len << "\n";

    return 0;
}

