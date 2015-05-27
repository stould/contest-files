import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;
 
public class ElectricCarRally {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		while (true) {
			int n = in.nextInt(), m = in.nextInt();
			if (n == 0 && m == 0)
				break;
			
			LinkedList<Interval>[] a = new LinkedList[n];
			for (int i = 0; i < n; i++)
				a[i] = new LinkedList<Interval>();
			
			for (int i = 0; i < m; i++) {
				int p = in.nextInt(), q = in.nextInt();
				while (true) {
					int s = in.nextInt(), t = in.nextInt(), w = in.nextInt();
					if (w <= 240) {
						a[p].add(new Interval(q, s, t, w * 2));
						a[q].add(new Interval(p, s, t, w * 2));
					}
					if (t == 1439)
						break;
				}
			}
 
			int best = Integer.MAX_VALUE;
			final int[] dist = new int[n * 481], localtime = new int[n * 481];
			Arrays.fill(dist, Integer.MAX_VALUE);
 
			PriorityQueue<Integer> que = new PriorityQueue<Integer>(n, new Comparator<Integer>() {
					public int compare(Integer i, Integer j) {
						return dist[i] == dist[j] ? j - i : Integer.compare(dist[i], dist[j]);
					}
				});
 
			que.add(0 * 481 + 480);
			dist[que.peek()] = 0;
			localtime[que.peek()] = 720;
 
			while (!que.isEmpty()) {
				int p = que.poll();
				if (dist[p] > best)
					continue;

				
				int fuel = p % 481;
				int node = p / 481;
				
				//System.out.println(node + " " + fuel + " " + dist[p]);
				
				if (node == n - 1)					
					best = Math.min(best, dist[p]);
 
				for (Interval i : a[node]) {
					int wait = Math.max(i.distance - fuel, 0);
					int time = (localtime[p] + wait) % 1440;
					if (time < i.begin) {
						wait += i.begin - time;
						time = i.begin;
					}
					if (time > i.end) {
						wait += 1440 - time + i.begin;
						time = i.begin;
					}
 
					int total = dist[p] + wait + i.distance / 2;
					int newfuel = Math.min(wait + fuel, 480) - i.distance;
					int newnode = i.to * 481 + newfuel;
					if (dist[newnode] > total && total <= best) {
						dist[newnode] = total;
						
						localtime[newnode] = (time + i.distance / 2) % 1440;
						//System.out.println("Go " + node + " to:  " + newnode / 481 + " dst: " + i.distance + " fuel: " + newfuel + " dist => " + dist[newnode] + " daytime: " + localtime[newnode]);
						que.add(newnode);
					}
				}
			}
 
			System.out.println(best == Integer.MAX_VALUE ? 0 : best);
		}
	}
 
	static class Interval {
		int begin, end, distance, to;
 
		Interval(int v, int s, int t, int w) {
			to = v;
			begin = s;
			end = t;
			distance = w;
		}
	}
}
