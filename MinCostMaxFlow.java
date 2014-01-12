class MinimumCostMaximumFlow {
    static class Edge {
        public int from;
        public int to;
        public long capacity;
        public int cost;
        public int next;
 
        public Edge(int from, int to, long capacity, int cost, int next) {
            this.from = from;
            this.to = to;
            this.capacity = capacity;
            this.cost = cost;
            this.next = next;
        }
    }
   
    public long maxFlow;
    public long minCost;
   
    public static long INF = (long)1e16;
   
    private int s;
    private int t;
    private int N;
    private int edgeCount;
    private ArrayList<Edge> edges;
    private int[] next;
    private int[] queue;
    private long[] distance;
    private int[] pre;
    private boolean[] visited;
   
    public MinimumCostMaximumFlow(int s, int t, int N) {
        this.s = s;
        this.t = t;
        this.N = N;
        this.edges = new ArrayList<Edge>(N);
        this.next = new int[N];
        this.queue = new int[N];
        this.distance = new long[N];
        this.pre = new int[N];
        this.visited = new boolean[N];
     
        Arrays.fill(next, -1);
    }
   
    public void execute() {
        while (spfa()) {
            increase();
        }
    }
   
    public void addEdge(int from, int to, long capacity, int cost) {
        add(from, to, capacity, cost);
        add(to, from, 0, -cost);
    }
   
    private void add(int from, int to, long capacity, int cost) {
        edges.add(new Edge(from, to, capacity, cost, next[from]));
        next[from] = edgeCount;
        edgeCount++;
    }
    
    private boolean spfa() {
        Arrays.fill(visited, false);
        Arrays.fill(distance, INF);
        Arrays.fill(pre, -1);
     
        int head = 0;
        int tail = 1;
        queue[head] = s;
        distance[s] = 0;
        visited[s] = true;
     
        while (head != tail) {
            int u = queue[head];
            for (int i = next[u]; i != -1; i = edges.get(i).next) {
                int v = edges.get(i).to;
                if (edges.get(i).capacity > 0 && distance[u] + edges.get(i).cost < distance[v]) {
                    distance[v] = distance[u] + edges.get(i).cost;
                    pre[v] = i;
                    if (!visited[v]) {
                        visited[v] = true;
                        queue[tail++] = v;
                        if (tail == N) {
                            tail = 0;
                        }
                    }
                }
            }
            visited[u] = false;
            head++;
            if (head == N) {
                head = 0;
            }
        }
        return distance[t] != INF;
    }
   
    private void increase() {
        long delta = Long.MAX_VALUE;
        for (int i = pre[t]; i != -1; i = pre[edges.get(i).from]) {
            delta = Math.min(delta, edges.get(i).capacity);
        }
        maxFlow += delta;
        for (int i = pre[t]; i != -1; i = pre[edges.get(i).from]) {
            edges.get(i).capacity -= delta;
            edges.get(i ^ 1).capacity += delta;
            minCost += edges.get(i).cost * delta;
        }
    }
}
