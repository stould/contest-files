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

using namespace std;

typedef long long Int;
typedef unsigned uint;

int T, N;
char pr[60], in[60];
vector<char> buff;

struct node {
	int v;
	char type;

	node* l;
	node* r;

	node() {
		l = NULL;
		r = NULL;
	}

	node(int vv, char ttype) {
		v = vv;
		type = ttype;
		l = NULL;
		r = NULL;
	}
};

void insert(node** n, int v, char t) {
	if ((*n) == NULL) {
		(*n) = new node(v, t);
	} else {
		if ((*n)->v > v) {
			insert(&(*n)->l, v, t);
		} else {
			insert(&(*n)->r, v, t);
		}
	}
}

void post(node** n) {
	if ((*n) != NULL) {
		post(&(*n)->l);
		post(&(*n)->r);
		buff.push_back((*n)->type);
	}
}

int main(void) {
	for ( ; scanf("%s%s", pr, in) == 2; ) {		
		node* root = NULL;

		N = strlen(pr);

		for (int i = 0; i < N; i++) {
			int v = 0;
			for (int j = 0; j < N; j++) {
				if (pr[i] == in[j]) {
					v = j;
					break;
				}
			}
			insert(&root, v, pr[i]);
		}
		buff.clear();
		post(&root);
		for (int i = 0; i < N; i++) {
			putchar(buff[i]);
		}
		printf("\n");
	}

    return 0;
}
