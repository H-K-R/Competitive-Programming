/**
*   Name : SOD
*   Description : Find sum of divisor of a given number
*				σ(n)=(p1^(e1+1)-1)/(p1−1) * (p2^(e2+1)−1)/(p2−1)***(pk^(ek+1)−1)(pk−1)
*	Complexity : O(sqrt(n)) , Squre root porjnto jotogula prime ase
*	Use : store prime up to squreroot(n) by efficient sieve, in = number of prime
*/


ll SOD(ll n){
    ll i,cnt,sum=1,tmp,B;
    for(i=1;i<=in&&pr[i]*pr[i]<=n;i++){
            cnt=0;
            while(n%pr[i]==0){
                cnt++;
                n /= pr[i];
            }
            tmp = pr[i];
            if(cnt){
                sum *= ((bgM(tmp,cnt+1)-1+MD)%MD)*(modi(tmp-1))%MD;
            }
            sum = sum%MD;
        }
        tmp = n;
        if(n>1){
            sum *= ((bgM(tmp,2)-1+MD)%MD)*(modi(tmp-1))%MD;
            sum = sum%MD;
        }
    return sum;
}
