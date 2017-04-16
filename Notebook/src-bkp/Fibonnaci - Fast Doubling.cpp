typedef long long int lli;
typedef pair<lli, lli> ii;

ii fast_doubling(lli n, lli mod) {
	if(n == 1) return ii(1, 1);
	else if(n == 2) return ii(1, 2);
	
	ii aux = fast_doubling(n/2, mod);
	ii ret;
	ret.first = (aux.first*(aux.second*2 + mod - aux.first))%mod;
	ret.second = ((lli)pow(aux.first, 2)+(lli)pow(aux.second, 2))%mod;
	
	if(n%2 == 0) {
		return ret;
	} else {
		return ii(ret.second, (ret.first+ret.second)%mod);
	}
}
