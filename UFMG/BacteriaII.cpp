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

const int MAXN = 20 * 20010 + 10;

int N;
string S[22], T;
int lcp[MAXN], rnk[MAXN];

void fix(int id) {
	int M = (int) T.size();

	for ( ; ; ) {
		bool ok = false;
		for (int i = 0; i < S[id].size() - M; i++) {			
			if (S[id].substr(i, M) == T) {
				S[id] = S[id].substr(0, i) + S[id].substr(i + M, S[id].size() - (i + M));
				ok = true;
				break;
			}
		}
		if (!ok) break;
	}
}

int delta, SA[MAXN], iSA[MAXN], val[MAXN], tval[MAXN];

bool cmp(const int& a, const int& b) {
    return val[a+delta] < val[b+delta];
}

void build_SA(string arg) {
	int len = (int) arg.size();
	
    for (int i = 0; i<len; i++) val[i] = arg[i];
    for (int i = 0; i<len; i++) SA[i] = i;

    delta = 0;
    sort(SA, SA+len, cmp);

    for(int delta = 1; ; delta *= 2) {
        bool found = false;
        for(int i = 0; i < len; i++) {
            for(int j = i + 1; j < len; j++) {
				if(val[SA[i]] != val[SA[j]]) break;				
				if (j > i+1) {
					found = true;
					sort(SA+i, SA+j, cmp);
				}
				i = j - 1;
			}
		}
		
        if(!found) break;
        tval[SA[0]] = 0;
        for(int i = 1; i < len; i++) {
            tval[SA[i]] = tval[SA[i-1]];
            if(val[SA[i]] == val[SA[i-1]] && val[SA[i]+delta] == val[SA[i-1]+delta]);
            else tval[SA[i]]++;
        }
        memcpy(val, tval, len * sizeof(int));
    }
}


void getLcp(string arg, int n){
    for (int i=0; i<n; ++i) rnk[SA[i]] = i;
    lcp[0] = 0;
    for (int i=0, h=0; i<n; ++i){
        if (rnk[i] > 0){
            int j = SA[rnk[i]-1];
            while (i + h < n && j + h < n && arg[i+h] == arg[j+h]) h++;
            lcp[rnk[i]] = h;
            if (h > 0) h--;
        }
    }
}

int check(string seen) {
	int ans = 0;

	for (int i = 0; i < N; i++) {
		if (S[i].find(seen) != string::npos) {
			ans += 1;
		}
	}
	
	return ans;
}

const int maxState = maxN << 1;
 
struct State {
	State *go[26], *suffix;
	int depth, id;
	long long cnt;
};
State pool[maxState], *point, *root, *sink;
int size;
 
State *newState(int dep) {
	point->id = size++;
	point->depth = dep;
	return point++;
}
 
void init() {
	point = pool;
	size = 0;
	root = sink = newState(0);
}
 
void insert(int a) {
	State *p = newState(sink->depth+1);
	State *cur = sink, *sufState;
	while (cur && !cur->go[a]) {
		cur->go[a] = p;
		cur = cur->suffix;
	}
	if (!cur)
		sufState = root;
	else {
		State *q = cur->go[a];
		if (q->depth == cur->depth + 1)
			sufState = q;
		else {
			State *r = newState(cur->depth+1);
			memcpy(r->go, q->go, sizeof(q->go));
			r->suffix = q->suffix;
			q->suffix = r;
			sufState = r;
			while (cur && cur->go[a] == q) {
				cur->go[a] = r;
				cur = cur->suffix;
			}
		}
	}
	p->suffix = sufState;
	sink = p;
}
 
int work(char buf[]) {
	//printf("%s", buf);
	int len = strlen(buf);
	int tmp = 0, ans = 0;
	State *cur = root;
	for (int i = 0; i < len; i++) {
		if (cur->go[buf[i]-'a']) {
			tmp++;
			cur = cur->go[buf[i]-'a'];
		} else {
			while (cur && !cur->go[buf[i]-'a'])
				cur = cur->suffix;
			if (!cur) {
				cur = root; tmp = 0;
			} else {
				tmp = cur->depth + 1;
				cur = cur->go[buf[i]-'a'];
			}
		}
		ans = max(ans, tmp);
	}
	return ans;
} 

struct node {
	node*go[26],*fa;
	int l,num,lcs,nlcs;
} sam[N],*root=sam,*last=sam;

int cur;

void expand(int x) {
	cur++;node*p=&sam[cur],*tp=last;p->num=cur;
	p->lcs=p->l=tp->l+1;last=p;
	for(;tp&&!tp->go[x];tp=tp->fa)tp->go[x]=p;
	if(!tp){
		p->fa=root;
	}else{
		if(tp->go[x]->l==tp->l+1)p->fa=tp->go[x];
		else{
			cur++;node*r=&sam[cur],*q=tp->go[x];
			*r=*q;r->num=cur;r->l=r->lcs=tp->l+1;
			r->fa=q->fa;q->fa=p->fa=r;
			for(;tp&&tp->go[x]==q;tp=tp->fa)tp->go[x]=r;
		}
	}
}

char st[N];
int d[N];
node* b[N]; 

int main(void) {
	ios_base::sync_with_stdio(false);
	for ( ; cin >> N; ) {
		for (int i = 0; i < N; i++) {
			cin >> S[i];
		}
		
		cin >> T;

		init();
		
		for (int i = 0; i < N; i++) {
			fix(i);
			for (int j = 0; j < (int) S[i].size(); j++) {
				insert(S[i] - 'A');
			}
		}

		int L = (int) all.size();

		build_SA(all);
		getLcp(all, L);

		int best = 0;
		string ans = "";
		
		//cout << all << endl;
		for (int i = 1; i < L; i++) {
			//cout << lcp[i] << " ";
			string curr = all.substr(SA[i- 1], all.size() - SA[i - 1]).substr(0, lcp[i]);

			if (check(curr) == N) {
				if (curr.size() > best || (curr.size() == best && curr < ans)) {
					best = lcp[i];
					ans = curr;
				}
			}
			
		}
		cout << ans << "\n";
	}
    return 0;
}

