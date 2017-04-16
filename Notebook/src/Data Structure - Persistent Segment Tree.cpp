//Persistent Segment Tree
int root[MAXQ]; //The root of the new node
int INDEX;
int Lef[MAXN*4*LOGMAXVAL];
int Rig[MAXN*4*LOGMAXVAL];
int S[MAXN*4*LOGMAXVAL];

struct PersistentSegTree{

    PersistentSegTree(){
		INDEX = 1;
        build(0, 0, MAXN);
    }
	
	//build the initial and empty tree
    void build(int node, int l, int r){
        if(l == r){
            return;
        }else{
            int mid = (l+r) / 2;
            Lef[node] = INDEX++;
            Rig[node] = INDEX++;
            build(Lef[node], l, mid);
            build(Rig[node], mid+1, r);
        }
    }
 
	/*query to count how many elements are > K
	  here is the key of the problem.*/
    int query(int node, int l, int r, int K){
		if(r <= K){
			return 0;
		}else if(l > K){
            return S[node];
        }else{
            int mid = (l+r) / 2;
            return query(Lef[node], l, mid, K) + query(Rig[node], mid+1, r, K);
        }
    }
 
	/*add a new node, we just need to copy log(n) nodes 
	  from the previus tree add add the new one*/
    int update(int node, int l, int r, int pos){
        int next = INDEX++;
        Lef[next] = Lef[node];
        Rig[next] = Rig[node];
        S[next] = S[node];
        if(l == r){
            S[next] += 1;
        }else{
            int mid = (l+r) / 2;
            if(pos <= mid){
                Lef[next] = update(Lef[node], l, mid, pos);
            }else{
                Rig[next] = update(Rig[node], mid+1, r, pos);
            }
            S[next] = S[Lef[next]] + S[Rig[next]];
        }
        return next;
    }
};
