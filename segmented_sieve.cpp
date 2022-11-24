
/// *** Segmented Sieve O( sqrt(up) + prime sieve )

/** [l = lower limit, u = upper limit]
*   [first generate all prime upto sqrt(upper limit)]
*   [Checking prime
*   n = number into that segment]
*   if(!mark[n-l]) then it is prime
*/
bool mark[u-l];
void segsiv(ll l, ll u)
{
    ll i,j,lt;
    if(l==1) mark[0] = 1;
    for(i=1; i<=in&&pr[i]*pr[i]<=u; i++){
        lt = l/pr[i];
        lt *= pr[i];
        if(lt<l) lt += pr[i];
        if(pr[i]==lt) lt += pr[i];
        for(lt; lt<=u; lt+=pr[i]){
            mark[lt-l] = 1;
        }
    }
}


