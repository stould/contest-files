//Kruskal Algorithm
struct edge {
    int from, to, cost;
    edge() {}
    edge(int from, int to, int cost): from(from), to(to), cost(cost) {};

    bool operator<(const edge& e) const {
		return cost < e.cost;
    }
};
//Sendo 'M' o numero de arestas, 'u' uma implementação do conjunto disjunto 'UnionFind' e 'ans' o menor custo
vector<edge> edges; //Populado com as arestas
int ans = 0;
UnionFind u(N);
for(i = 0; i < m; i++) {
	if(!u.find(edges[i].from, edges[i].to)) {
		u.unite(edges[i].from, edges[i].to);
		ans += edges[i].cost;
	}
}
