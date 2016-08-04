
int T[MAX_AHO], term[MAX_AHO], sig[MAX_AHO][MAX_ALPHA], cnt;
vector <int> indice[MAX];

void add(string& arg) {
    int x = 0, n = (int) arg.size();

    for (int i = 0; i < n; i++){
        int c = (int) arg[i];
        if (sig[x][c] == 0) {
            term[cnt] = 0;
            sig[x][c] = cnt++;
        }
        x = sig[x][c];
    }
    term[x] = 1;
}


void aho() { 
    queue <int> q;
    for (int i = 0; i < cc; i++){
        int v = sig[0][i];

        if (v > 0) {
            q.push(v);
            T[v] = 0;
        }
    }
    while (!q.empty()){
        int u = q.front();
        q.pop();
        
        for (int i = 0; i < cc; i++){
            int x = sig[u][i];

            if (x == 0) {
                continue;
            }
            
            int v = T[u];

            while (sig[v][i] == 0 && v != 0) {
                v = T[v];
            }

            int y = sig[v][i];
            q.push(x);
            
            T[x] = y;
            term[x] |= term[y];
        }
    }
}

void busca (char s[MAXT]){
    int n = strlen (s);
    int pos = 0;
    for (int i = 0; i < n; i++){
        if (sig[pos][s[i]-'A'] != 0){
            pos = sig[pos][s[i]-'A'];
            if (term[pos]){
                for (int j = 0; j < indice[pos].size(); j++)
                    printf("%d ", indice[pos][j]);
                printf("\n");
            }
        }
        else {
            if (pos != 0) i--;
            pos = T[pos];
        }
    }
}

int main (){
    char t[MAXS]; char texto[MAXT];
    int N;
    scanf("%d", &N);
    for (int i = 0; i < MAX; i++) indice[i].clear();
    cnt = 1;
    memset (sig, 0, sizeof (sig));
    for (int i = 0; i < N; i++){
        scanf("%s", t);
        add (t, i);
    }
    aho();
    scanf("%s", texto);
    busca (texto);
    return 0;
}


