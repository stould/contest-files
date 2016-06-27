#include <iostream>
#include <cstdlib>
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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

struct Node {
    Node* L;
    Node* R;
	
    int value;
    int priority;
    int id;
    int size;

    Node(int v, int i) {
        value = v;
        id = i;
        size = 1;
        priority = rand() % 100000000;
    }
	
    void update_size() {
        size = 1;
		
        if (L) {
            size += L->size;
        }
        if (R) {
            size += R->size;
        }
    }
};

void split(Node* root, Node*& l, Node*& r, int val) {
    if (!root) {
        l = NULL;
        r = NULL;
    } else {
        if (root->value <= val) {
            split(root->R, root->R, r, val);
            l = root;
        } else {
            split(root->L, l, root->L, val);
            r = root;
        }
    }
    if (root) {
        root->update_size();
    }
}

void merge(Node*& root, Node*& l, Node*& r) {	
    if (l == NULL || r == NULL) {
        if (l != NULL) {
            root = l;
        } else {
            root = r;
        }
    } else {
        if (l->priority > r->priority) {
            merge(l->R, l->R, r);
            root = l;
        } else {
            merge(r->L, l, r->L);
            root = r;
        }
    }
    if (root) {
        root->update_size();
    }
}

void insert(Node*& root, Node*& inserted) {
    if (root == NULL) {
        root = inserted;
    } else {
        if (root->priority < inserted->priority) {			
            split(root, inserted->L, inserted->R, inserted->value);
            root = inserted;
        } else {
            if (root->value <= inserted->value) {
                insert(root->R, inserted);
            } else {
                insert(root->L, inserted);
            }
        }
    }
    if (root) {
        root->update_size();
    }
}

void remove(Node*& root, int value) {
    if (root == NULL) {
        return;
    } else {
        if (root->value == value) {
            merge(root, root->L, root->R);
        } else {
            if (root->value < value) {
                remove(root->R, value);
            } else {
                remove(root->L, value);
            }
        }
    }
    if (root) {
        root->update_size();
    }
}

bool find(Node* root, int value) {
    if (root == NULL) {
        return false;
    } else if (root->value == value) {
        return true;
    } else {
        if (root->value <= value) {
            return find(root->R, value);
        } else {
            return find(root->L, value);
        }
    }
}

Node* getMax(Node* root) {
    if (root->R == NULL) {
        return root;
    } else {		
        return getMax(root->R);
    }
}
Node* getMin(Node* root) {
    if (root->L == NULL) {
        return root;
    } else {		
        return getMin(root->L);
    }
}


int main(void) {
    int kind;
    Node* root = NULL;
    
    while (cin >> kind && kind != 0) {        
        if (kind == 1) {
            int val, pri;
            
            cin >> val >> pri;
            
            Node* buff = new Node(pri, val);
            insert(root, buff);
        } else if (kind == 2) {
            if (root == NULL) {
                cout << 0 << endl;
            } else {
                Node* nd = getMax(root);
                cout << nd->id << endl;
                remove(root, nd->value);
            }
        } else {
            if (root == NULL) {
                cout << 0 << endl;
            } else {
                Node* nd = getMin(root);
                cout << nd->id << endl;
                remove(root, nd->value);
            }
        }
    }
    return 0;
}
