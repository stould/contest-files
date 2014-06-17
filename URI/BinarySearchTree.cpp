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

struct node {
	int v;	
	node *l;
	node *r;

	node() {
		v = -1;
		l = NULL;
		r = NULL;
	}

	node(int vv) {
		v = vv;
		l = NULL;
		r = NULL;
	}
};

void insert(node** n, int v) {
	if ((*n) == NULL) {
		*n = new node(v);
	} else {
		if ((*n)->v > v) {
			insert(&(*n)->l, v);
		} else {
			insert(&(*n)->r, v);
		}
	}
}

int T, N;
vector<int> buff;

void prefix(node** n) {
	if ((*n) != NULL) {
		buff.push_back((*n)->v);
		if ((*n)->l != NULL) prefix(&(*n)->l);
		if ((*n)->r != NULL) prefix(&(*n)->r);
	}
}

void infix(node** n) {
	if ((*n) != NULL) {
		if ((*n)->l != NULL) infix(&(*n)->l);
		buff.push_back((*n)->v);
		if ((*n)->r != NULL) infix(&(*n)->r);
	}
}

void postfix(node** n) {
	if ((*n) != NULL) {
		if ((*n)->l != NULL) postfix(&(*n)->l);
		if ((*n)->r != NULL) postfix(&(*n)->r);
		buff.push_back((*n)->v);
	}
}

void clear(node** n) {
	if ((*n) != NULL) {
		if ((*n)->l != NULL) clear(&(*n)->l);
		if ((*n)->r != NULL) clear(&(*n)->r);
		delete (*n);
	}
}

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;

		node* root = NULL;

		for (int i = 0; i < N; i++) {
			int curr;
			cin >> curr;
			insert(&root, curr);
		}
		cout << "Case " << t << ":\n";
		cout << "Pre.: ";
		buff.clear();
		prefix(&root);
		for (int i = 0; i < N; i++) {
			printf("%d", buff[i]);
			if (i != N - 1) printf(" ");
			else printf("\n");
		}		
		cout << "In..: ";
		buff.clear();
		infix(&root);
		for (int i = 0; i < N; i++) {
			printf("%d", buff[i]);
			if (i != N - 1) printf(" ");
			else printf("\n");
		}	
		cout << "Post: ";
		buff.clear();
		postfix(&root);
		for (int i = 0; i < N; i++) {
			printf("%d", buff[i]);
			if (i != N - 1) printf(" ");
			else printf("\n");
		}	
		printf("\n");
		//		clear(&root);
	}

    return 0;
}
