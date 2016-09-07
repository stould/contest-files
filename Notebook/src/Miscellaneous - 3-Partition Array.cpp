Int sum[MAXN], cnt[MAXN], suffix[MAXN], v[MAXN];
Int waysToTear() {
  suffix[n] = 0;
  sum[0] = 0;
  for(int i = 0; i < n; i++){
    sum[i] = v[i];
    if(i) sum[i] += sum[i-1];
  }
  for(int i = n-1; i >= 0; i--){
	suffix[i] = v[i] + suffix[i+1];
  }
  if(sum[n-1] % 3 != 0) return 0;
  Int top = sum[n-1] / 3, ans = 0;
  for(int i = 0; i < n; i++){
	if(sum[i] == top) cnt[i] = 1;
	else cnt[i] = 0;
	if(i) cnt[i] += cnt[i-1];
  }
  for(int i = 2; i < n; i++){
	if(suffix[i] == top){
		ans += cnt[i-2];
	}
  }
  return ans;
}
