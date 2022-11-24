/**
*	Description : normal prime factorization   
*	Complexity : O(sqrt(n))
*	Use : store prime up to squreroot(n) by efficient sieve, in = number of prime
*/


void primeFactorization(ll n){
	ll i,cn=0;	
	for(i=1; i <= in && (ll)pr[i]*(ll)pr[i] <= n; i++){
        cn = 0;
    	while(n%pr[i] == 0){
        	n /= pr[i];
        	cn++;
        }
        // cn is the prime power
    }
    if(n>1) // then n is a prime
}
