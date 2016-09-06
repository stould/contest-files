#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100010
#define inf 2000000000
struct no{
    int x,y;
};

no v[MAX];
int n;
set <pair<int,int> > S[MAX];
int topo;
set <pair<int, int> > :: iterator it, it2, ini, fim;
vector <pair<int, int> > aux;

bool cobre (pair <int, int> p, int s){
	it2 = S[s].lower_bound (make_pair (p.first-1, inf));
	if (it2 == S[s].begin()) return false;
	it2--; 
	if (p.second > (*it2).second) return true;
	return false;
}

int main (){
    pair <int, int> p;
    	topo = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++){
            scanf("%d %d", &v[i].x, &v[i].y);
        }
        for (int i = 0; i < n; i++) S[i].clear();
        int ans = 0;
        
        p = make_pair (v[0].x, v[0].y);
        S[topo++].insert (p);
        
        for (int i = 1; i < n; i++){
        	/*cria o pair do ponto i*/
            p = make_pair (v[i].x, v[i].y);
            /*busca*/
            /*verifica se ele cobre a ultima linha de parreto*/
            if (cobre(p, topo-1)){
            	S[topo++].insert (p);
            	continue;
            }
            /*faz busca binaria pra descobrir menor linha q ele nao cubra ninguem*/
            int u = 0, v = topo-1;
            while (u < v-1){
            	int mid = (u+v)/2;
            	if (cobre(p, mid)) u = mid;
            	else v = mid;
            }
            int quem;
            if (cobre (p, u)) quem  = v;
            else  quem = u;
            /*insercao*/
            /*insere na linha de parreto, removendo quem for necessario*/
            aux.clear();
            ini = S[quem].lower_bound (make_pair (p.first-1, inf));

            if (ini != S[quem].begin()){
                ini--;
                if ((*ini).second <= p.second) continue;
                ini++;
            }
            for (it = ini; it != S[quem].end() && (*it).second > p.second; it++){
                aux.push_back(*it);
            }
            for (int j = 0; j < aux.size(); j++){
                S[quem].erase(S[quem].find(aux[j]));
            }
            ans++;
            S[quem].insert (p);
         }
        printf("%d\n", topo);
    return 0;
}

