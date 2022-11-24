
/// ***Number of divisors [Quberoot(n)]

/** There can be only two prime after qube root
*   so we factorize upto quberoot by the trial divison then
*   handle ramainig <=2 prime
*   Miller Rabin needed
*/

ll NOD(ll n){
    ll i,j,r,nod=1,cn;
    for(i=1;i<=in&&(pr[i]*pr[i]*pr[i])<=n;i++){
        cn = 1;
        while(n%pr[i]==0){
            n /= pr[i];
            cn++;
        }
        nod *= cn;
    }

    r = sqrtl(n);
    while((r+1)*(r+1)<=n) r++;

    if(MillerRabin(n,8)) nod *= 2;
    else if(r*r==n&&MillerRabin(r,8)) nod *= 3;
    else if(n!=1) nod *= 4;

    return nod;
}

