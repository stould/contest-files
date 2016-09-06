//Sliding RMQ in O(N) - Faster (No use of STL)
int Q[MAXN];

Int maxSlidingWindow(Int A[], int n, int w, Int B[]) {
	int b = 0, e = 0;
	Int ans = 0LL;
	for (int i = 0; i < w; i++) {
		while (!(b == e) && A[i] >= A[Q[e-1]]) {
			e -= 1;
		}
		Q[e++] = i;
	}
	for (int i = w; i < n; i++) {
		B[i-w] = A[Q[b]];
		ans += B[i-w];
		while (!(e == b) && A[i] >= A[Q[e-1]])
			e--;
		while (!(e == b) && Q[b] <= i-w)
			b += 1;
		Q[e++] = i;
	}
	ans += A[Q[b]];

	return ans;
}
