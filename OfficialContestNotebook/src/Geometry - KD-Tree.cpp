#include <bits/stdc++.h>
using namespace std;
typedef long long Int;

struct point { 
    Int x, y, z;
    point(Int x=0, Int y=0, Int z=0): x(x), y(y), z(z) {}
    point operator-(point q) { return point(x-q.x, y-q.y, z-q.z); }
    Int operator*(point q) { return x*q.x + y*q.y + z*q.z; }
};
typedef vector<point> polygon;

struct KDTreeNode {
    point p;
    int level;
    KDTreeNode *left, *right;
	
    KDTreeNode (const point& q, int levl) {
        p = q;
        level = levl;
        left = right = 0;
    }
    ~KDTreeNode() { delete left; delete right; }
	
    int diff (const point& pt) {
        switch (level) {
        case 0: return pt.x - p.x;
        case 1: return pt.y - p.y;
        case 2: return pt.z - p.z;
        } 
        return 0;
    }
    Int distSq (point& q) { return (p-q)*(p-q); }

    int rangeCount (point& pt, Int K) {
        int count = (distSq(pt) < K*K) ? 1 : 0;
        int d = diff(pt);
        if (-d <= K && right != 0)
            count += right->rangeCount(pt, K);
        if (d <= K && left != 0)
            count += left->rangeCount(pt, K);
        return count;
    }
};

class KDTree {
public:
    polygon P;
    KDTreeNode *root;
    int dimention;
    KDTree() {}
    KDTree(polygon &poly, int D) {
        P = poly;
        dimention = D;
        root = 0;
        build();
    }
    ~KDTree() { delete root; }
		
    //count the number of pairs that has a distance less than K
    Int countPairs(Int K) {
        Int count = 0;
		for (int i = 0; i < (int) P.size(); i++) {
            count += root->rangeCount(P[i], K) - 1;
		}
        return count;
    }
		
protected:
    void build() {
        random_shuffle(P.begin(), P.end());
		for (int i = 0; i < (int) P.size(); i++) {
            root = insert(root, P[i], -1);
        }
    }
    KDTreeNode *insert(KDTreeNode* t, const point& pt, int parentLevel) {
        if (t == 0) {
            t = new KDTreeNode (pt, (parentLevel+1) % dimention);
            return t;
        } else {
            int d = t->diff(pt);
            if (d <= 0) t->left = insert (t->left, pt, t->level);
            else t->right = insert (t->right, pt, t->level);
        }
        return t;
    }
};

int main() {
    int n, k;
    point e;
    polygon p;
    while (cin >> n >> k && n+k) {
        p.clear();
		for (int i = 0; i < n; i++) {
            cin >> e.x >> e.y >> e.z;
            p.push_back(e);
        }
        KDTree tree(p, 3);
        cout << tree.countPairs(k) / 2LL << endl;
    }
    return 0;
}
