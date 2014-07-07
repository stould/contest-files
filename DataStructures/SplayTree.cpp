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

struct Node {
	int value, size;
	Node *left, *right, *parent;

	Node(int value): value(value), size(1), left(NULL), right(NULL), parent(NULL) {
		
	}
};

struct SplayTree {
	Node *root;
	int size;

	SplayTree(): root(0), size(0) {

	}

	void right_rotation(Node *node) {
		
	}

	void splay(Node *node) {

	}

	void insert(int value) {
		Node *buff = root, *parent = NULL;
		
		while (buff) {
			parent = buff;
			if (buff->value <= value) {
				buff = buff->left;
			} else {
				buff = buff->right;
			}
		}
		buff = new Node(value);
		buff->parent = parent;

		if (!parent) {
			root = buff;
		} else if (parent->value > buff->value) {
			parent->left = buff;
		} else {
			parent->right = buff;
		}
		splay(buff);
	}
};

int main(void) {
    return 0;
}
