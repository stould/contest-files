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

template<typename T>
struct BST {
	struct node {
		T value;
		node *left, *right, *parent;

		node(T value): value(value), left(NULL), right(NULL) {}
	};

	node* root;

	BST(): root(NULL) {}

	bool insert(T value) {
		if (root == NULL) {
			root = new node(value);
			return true;
		}

		node* buff = root;
		bool ok = false;

		while (!ok) {
			if (value == buff->value) {
				return false;
			} else if (value < buff->value) {
				if (buff->left == NULL) {
					buff->left = new node(value);
					ok = true;
				} else {
					buff = buff->left;
				}
			} else {
				if (buff->right == NULL) {
					buff->right = new node(value);								
					ok = true;
				} else {
					buff = buff->right;
				}
			}
		}
		

		return true;
	}

	bool find(T value) {
		node** buff = &root;

		while ((*buff) != NULL) {
			if (value == (*buff)->value) {
				return true;
			} else if (value < (*buff)->value) {
				buff = &(*buff)->left;
			} else {
				buff = &(*buff)->right;
			}
		}
		return false;
	}
	void _prefix(node* node, vector<T>& v_ans) {
		if (node != NULL) {
			v_ans.push_back(node->value);
			_prefix(node->left, v_ans);
			_prefix(node->right, v_ans);
		}
	}
	void _infix(node* node, vector<T>& v_ans) {
		if (node != NULL) {
			_infix(node->left, v_ans);
			v_ans.push_back(node->value);
			_infix(node->right, v_ans);
		}
	}
	void postfix(node* node, vector<T>& v_ans) {
		if (node != NULL) {
			postfix(node->left, v_ans);
			postfix(node->right, v_ans);
			v_ans.push_back(node->value);
		}
	}

	void infix(vector<T>& v_ans) {
		_infix(root, v_ans);
	}
	
	void prefix(vector<T>& v_ans) {
		_prefix(root, v_ans);
	}
	
	void postfix(vector<T>& v_ans) {
		postfix(root, v_ans);
	}
};

string S;
char C;

int main(void) {
	BST<char> tree;
	vector<char> buffer;

	for ( ; cin >> S; ) {
		buffer.clear();
		if (S == "I") {
			cin >> C;
			tree.insert(C);
		} else if (S == "P") {
			cin >> C;
			bool has = tree.find(C);

			if (has) {
				cout << C << " existe\n";
			} else {
				cout << C << " nao existe\n";
			}
		} else if (S == "R") {
			cin >> C;

			if (tree.finc(C)) {
				tree.erase(C);
			}
		} else {
			if (S == "PREFIXA") {
				tree.prefix(buffer);
			} else if (S == "INFIXA") {
				tree.infix(buffer);
			} else {
				tree.postfix(buffer);
			}
			for (int i = 0; i < (int) buffer.size(); i++) {
				if (i > 0) printf(" ");
				printf("%c", buffer[i]);
			}
			printf("\n");		
		}
	}
    return 0;
}
