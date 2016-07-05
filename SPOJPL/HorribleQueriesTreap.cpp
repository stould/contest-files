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

int T, N, M;

struct Node {
    Node* L;
    Node* R;
    
    Int value;
    int priority;
    int size;

    Int sum;
    Int lazy;
    
    Node(Int v) {
        value = v;
        size = 1;
        sum = v;
        lazy = 0;
        
        priority = rand() % 1000000;
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

    void updateLazy() {
        if (lazy) {
            value += lazy;
            sum += lazy * size;

            if (L) {
                L->lazy += lazy;                
            }
            if (R) {
                R->lazy += lazy;
            }
        }
        lazy = 0;
    }

    void fix() {
        sum = value;
        
        if (L) {
            L->updateLazy();
            sum += L->sum;
        }
        if (R) {
            R->updateLazy();
            sum += R->sum;
        }

        update_size();
    }
};

void split(Node* root, Node*& l, Node*& r, int pos, int add=0) {
    if (!root) {
        l = NULL;
        r = NULL;
    } else {
        root->updateLazy();
        
        int curr_pos = add;

        if (root->L) {
            curr_pos += (root->L)->size;
        }

        if (curr_pos <= pos) {
            split(root->R, root->R, r, pos, curr_pos + 1);
            l = root;
        } else {
            split(root->L, l, root->L, pos, add);
            r = root;
        }
    }
    if (root) {
        root->update_size();
        root->fix();
    }
}

void merge(Node*& root, Node*& l, Node*& r) {
    if (l) {
        l->updateLazy();
    }
    if (r) {
        r->updateLazy();
    }
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
        root->fix();
    }
}


void insert(Node*& root, int pos, int value) {
    Node* inserted = new Node(value);

    if (root == NULL) {
        root = inserted;
    } else {
        
        Node* left;
        Node* right;
        Node* buff;
        
        
        split(root, left, right, pos - 1);
        merge(root, left, inserted);
        merge(buff, root, right);
        root = buff;
    }
}

Int range_query(Node*& root, int l, int r) {
    Node* left;
    Node* mid;
    Node* right;

    split(root, left, mid, l-1);
    split(mid, root, right, r-l);
        
    Int ans = root->sum;
    
    merge(mid, left, root);
    merge(root, mid, right);
    
    return ans;
}

void range_update(Node*& root, int l, int r, Int val){
    Node* left;
    Node* mid;
    Node* right;
    
    split(root, left, mid, l-1);
    split(mid, root, right, r-l);

    root->lazy+=val;
    
    merge(mid, left, root);
    merge(root, mid, right);
}

int main(void) {
    cin >> T;

    while (T--) {
        cin >> N >> M;

        Node* root = NULL;

        for (int i = 0; i < N; i++) {
            insert(root, i, 0);
        }

        for (int i = 0; i < M; i++) {
            int kind;
            
            cin >> kind;
            
            if (kind == 0) {
                int P, Q, V;
                cin >> P >> Q >> V;

                P -= 1;
                Q -= 1;

                range_update(root, P, Q, V);                
            } else {
                int P, Q;
                cin >> P >> Q;

                P -= 1;
                Q -= 1;

                cout << range_query(root, P, Q) << endl;
            }
        }
    }
    return 0;
}
