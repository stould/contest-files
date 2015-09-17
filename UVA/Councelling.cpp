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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

int T;
string S;
map<string, int> id_name, id_party, id_club;
map<int, string> rev_name, rev_club;

int id_name_cnt, id_party_cnt, id_club_cnt;

const int MAXN = 101010;
const int INF = 10101;

struct edge {
    int to,rev;
    Int cap;
    edge(int to, Int cap, int rev): to(to), cap(cap), rev(rev) {}
};

vector<edge> G[MAXN];
Int level[MAXN];
int iter[MAXN];

void init(int N) {
    for (int i = 0; i < N; i++) {
        G[i].clear();
    }
}

void add_edge(int from,int to,Int cap) {
    G[from].push_back(edge(to, cap, G[to].size()));
    G[to].push_back(edge(from, 0, G[from].size()-1));
}

void bfs(int s) {
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);

    while(!que.empty()) {
        int v = que.front();
        que.pop();
        for (int i = 0; i < (int) G[v].size(); i++) {
            edge& e = G[v][i];
            if(e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

Int dfs(int v, int t, Int f) {
    if(v == t) return f;
    for(int& i = iter[v]; i < (int) G[v].size(); i++) {
        edge &e = G[v][i];
        if(e.cap > 0 && level[v] < level[e.to]) {
            Int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t) {
    Int flow = 0;
    for( ; ; ) {
        bfs(s);
        if (level[t] < 0) {
            return flow;
        }
        memset(iter, 0, sizeof(iter));
        int f;
        while ((f=dfs(s,t,INF*INF)) > 0) {
            flow += f;
        }
    }
}

vector<string> split(string arg) {
	vector<string> ans;
	istringstream ss(arg);
	string buff;

	while (ss >> buff) {
		ans.push_back(buff);
	}
	
	return ans;
}

struct data {
	string name;
	string party;

	vector<string> club;
};

int get_name(string arg) {
	if (id_name[arg] == 0) {
		rev_name[id_name_cnt] = arg;
		id_name[arg] = id_name_cnt++;
	}
	return id_name[arg];
}

int get_party(string arg) {
	if (id_party[arg] == 0) {
		id_party[arg] = id_party_cnt++;
	}
	return id_party[arg];
}

int get_club(string arg) {
	if (id_club[arg] == 0) {
		rev_club[id_club_cnt] = arg;
		id_club[arg] = id_club_cnt++;
	}
	return id_club[arg];
}


int main(void) {
	cin >> T;
	//cin.ignore();
	getline(cin, S);
	//cout << S  << "\n";
	//getline(cin, S);
	getline(cin, S);

	for ( ; T-- ; ) {
		for (int i = 0; i < MAXN; i++) {
			G[i].clear();
		}
		id_name.clear();
		id_party.clear();
		id_club.clear();

		id_name_cnt = id_party_cnt = id_club_cnt = 1;
		
		vector<data> vd;
		
		
		while (getline(cin, S)) {
			if (S.size() < 2) {
				break;
			}
			
			vector<string> sp = split(S);

			data buff;

			buff.name = sp[0];
			buff.party = sp[1];

		
			get_name(buff.name);
			get_party(buff.party);

			for (int i = 2; i < (int) sp.size(); i++) {
				buff.club.push_back(sp[i]);
				get_club(sp[i]);
			}
			vd.push_back(buff);
		}

		int s = 0;
		int t = id_club_cnt + id_name_cnt + id_party_cnt + 2;

		//cout << id_club_cnt << " " << id_name_cnt << " " << id_party_cnt << endl;
		
		//cerr << "src to club\n";
		for (int i = 1; i < id_club_cnt; i++) {
			//cout << 0 << " " << i << "\n";
			add_edge(0, i, 1);
		}
		
		//cout << "party to sink\n";
		for (int i = 1; i < id_party_cnt; i++) {
			//cout << id_club_cnt + id_name_cnt + i << " " << t << "\n";
			add_edge(id_club_cnt + id_name_cnt + i, t, id_club_cnt / 2 - 1);
		}

		for (int i = 0; i < (int) vd.size(); i++) {
			int name_id = get_name(vd[i].name);
			int party_id = get_party(vd[i].party);

			//cout << "name to party\n";
			//cout << id_club_cnt + name_id << " " << id_club_cnt + id_name_cnt + party_id << "\n";
			add_edge(id_club_cnt + name_id, id_club_cnt + id_name_cnt + party_id, 1);

			for (int j = 0; j < (int) vd[i].club.size(); j++) {
				int club_id = get_club(vd[i].club[j]);

				//cout << "club to name\n";
				//cout << club_id << " " << id_club_cnt + name_id << "\n";
				add_edge(club_id, id_club_cnt + name_id, 1);
			}
		}
		
		max_flow(s, t);

		vector<pair<int, int> > ans;
		
		for (int i = 1; i < id_club_cnt; i++) {
			for (int j = 0; j < (int) G[i].size(); j++) {
				if (G[i][j].cap == 0 && G[i][j].to != 0) {
					//cout << "end " << i << " " << G[i][j].to << endl;
					ans.push_back(make_pair(G[i][j].to - id_club_cnt, i));
				}
			}
		}

		if(ans.empty()) {
			cout << "Impossible.\n";
		} else {
			for (int i = 0; i < (int) ans.size(); i++) {
				//cout << ans[i].first << endl;
				cout << rev_name[ans[i].first] << " " << rev_club[ans[i].second] << "\n";
			}
		}
		cout << "\n";
	}
	
	return 0;
}
