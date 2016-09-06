const int MAXN = 100005;
const int LOGMAXVAL = 20;

int n, q, val[MAXN];
int BLOCK_SIZE = sqrt(MAXN)+5; 
int resp[MAXN];
int seen[MAXN];
int answer = 0;
 
struct pt{
    int l, r, id;
	
    pt(){}
    pt(int L, int R, int ID){
        l = L;
        r = R;
        id = ID;
    }
 
    bool operator < (const pt &o) const{
        return r < o.r;
    }
};
 
vector<vector<pt> > cons(BLOCK_SIZE);
 
void add(int pos){
    if(seen[val[pos]] == 1) {
        answer += 2;
    } else if (seen[val[pos]] > 1) {
        answer += 1;
    }
    seen[val[pos]]++;
}
 
void remove(int pos){
    if(seen[val[pos]] > 2){
        answer--;
    } else if (seen[val[pos]] == 2) {
        answer -= 2;
    }
    seen[val[pos]]--;
}
 
void process(int pos){
    int l = pos*BLOCK_SIZE, r = pos*BLOCK_SIZE, ql, qr, id;
    answer = 0;
    sort(cons[pos].begin(), cons[pos].end());
    for(int i = 0; i < (int) cons[pos].size(); i++){
        ql = cons[pos][i].l;
        qr = cons[pos][i].r;
        id = cons[pos][i].id;
        while(r < qr){
            add(r);
            r++;
        }
        while(l < ql){
            remove(l);
            l++;
        }
        while(l > ql){
            l--;
            add(l);
        }
        resp[id] = answer; 
    }
    for(int j = l; j < r; j++){
        remove(j);
    }
}

for (int i = 0; i < q; i++) {
    pt newQ;
    cin >> newQ.l >> newQ.r;
    newQ.id = i;
    //This is problem dependent, there are cases when newQ.r++ is necessary
    newQ.l--;
    cons[newQ.l / BLOCK_SIZE].push_back(newQ);
 }

for(int i = 0; i < BLOCK_SIZE; i++){
    if(cons[i].size()){
        process(i);
    }
 }
    
for (int i = 0; i < q; i++){
    printf("%d\n", resp[i]);
 }
