import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
 
class Main {
    BufferedReader in;
    PrintWriter out;
 
    public static void main(String[] args) throws Throwable {
        new Main().solve();
    }
 
    public void solve() throws Throwable {
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        int n, teste = 1;
 
        while (true) {
            n = Integer.parseInt(in.readLine());
            if (n == 0)
                break;
 
            Map<String, Integer> msi = new HashMap<String, Integer>();
            Map<Integer, String> mis = new HashMap<Integer, String>();
 
            msi.put("P. Erdos", 0);
            mis.put(0, "P. Erdos");
 
            List<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>();
            for (int i = 0; i < 110; i++) {
                graph.add(new ArrayList<Integer>());
                graph.get(i).addAll(new ArrayList<Integer>());
 
            }
            int[] dist = new int[110], vis = new int[110];
 
            Arrays.fill(dist, Integer.MAX_VALUE);
 
            int start = 1;
 
            for (int i = 0; i < n; i++) {
                String[] now = in.readLine().split("[,]");
                for (int j = 0; j < now.length; j++) {
                    if (j == now.length - 1) {
                        now[j] = now[j].substring(0, now[j].length() - 1);
                    }
                    now[j] = now[j].trim();
                    if (!msi.containsKey(now[j])) {
                        msi.put(now[j], start);
                        mis.put(start, now[j]);
                        start += 1;
                    }
                }
                for (int j = 0; j < now.length; j++) {
                    for (int k = 0; k < now.length; k++) {
                        if (j != k) {
                            graph.get(msi.get(now[j])).add(msi.get(now[k]));
                            graph.get(msi.get(now[k])).add(msi.get(now[j]));
                        }
                    }
                }
            }
            Queue<Integer> q = new LinkedList<Integer>();
            q.add(0);
            vis[0] = 1;
            dist[0] = 0;
 
            while (!q.isEmpty()) {
                int now = q.poll();
                for (int i = 0; i < graph.get(now).size(); i++) {
                    int next = graph.get(now).get(i);
                    if (vis[next] == 0) {
                        vis[next] = 1;
                        dist[next] = Math.min(dist[next], dist[now] + 1);
                        q.add(next);
                    }
                }
            }
 
            List<Autor> lu = new ArrayList<Autor>();
            for (Map.Entry<Integer, String> in : mis.entrySet()) {
                lu.add(new Autor(mis.get(in.getKey()), dist[in.getKey()]));
            }
            Collections.sort(lu);
            out.println("Teste " + teste++);
            for (int i = 0; i < lu.size(); i++)
                if (!lu.get(i).fullName.equals("P. Erdos")) {
                    out.println(lu.get(i).fullName + ": " + (lu.get(i).number == Integer.MAX_VALUE ? "infinito" : lu.get(i).number));
                }
            out.println();
        }
        out.close();
        System.exit(0);
    }
 
    public class Autor implements Comparable<Autor> {
        public String firstName, secondName, fullName;
        int number;
 
        public Autor(String name, int number) {
            this.fullName = name;
            this.firstName = name.substring(0, name.indexOf("."));
            this.secondName = name.substring(name.indexOf(".") + 2);
            this.number = number;
        }
 
        @Override
        public int compareTo(Autor arg0) {
            if (!this.secondName.equals(arg0.secondName)) {
                return this.secondName.compareTo(arg0.secondName);
            } else {
                return this.firstName.compareTo(arg0.firstName);
            }
        }
    }
}
