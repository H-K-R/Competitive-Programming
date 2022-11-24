/**
*   Name : NOD
*   Description : Therefore if the prime factorization of n is p1^e1⋅pi2^e2⋯pk^ek,
*		        where pi are distinct prime numbers, then the number of divisors is: d(n)=(e1+1)⋅(e2+1)⋯(ek+1)
*	Complexity : O(sqrt(n)) , Squre root porjnto jotogula prime ase
*	Use : store prime up to squreroot(n) by efficient sieve, in = number of prime
*/



ll NOD(ll n){
	ll ans=1,x,count;
	for(int i=0; (ll)prime[i] * (ll)prime[i]<=n && i<=in ;i++){
		int( n%prime[i] == 0){
			x=prime[i];
			count =1;
			while(n%x==0) {
				n/=x;
				count++;
			}
			ans*= count;
		}
	}
	if(n>1) ans*=2;
	return ans;
}

