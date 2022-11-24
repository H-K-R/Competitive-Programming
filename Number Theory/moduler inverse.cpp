
/// *** Modular Inverse [ log(n) ]

/**  [ large division = (upper%M)*modi(low)) ]
*    [ after modular division value should be moded ]
*    [ mainly it returns an iverse and multiplicable value ]
*    [ for loop == first loop throw all number(multiply) with simple mod -]
*    [- then modular inverse ]
*/

#define M 1000000007
#define pii pair<ll,ll>
pii extnuc(ll a,ll b)
{
    if(b==0)return pii(1,0);
    pii d=extnuc(b,a%b);
    return pii(d.second,d.first-d.second*(a/b));
}

ll modi(ll n) /// n must be moded value
{
    pii d=extnuc(n,M);
    return ((d.first%M)+M)%M;
}

///Now factorial & inverse factorial with MOD
void fact()
{
    ll i;
    fr[0]=fi[0]=1;
    for(i=1;i<2000007;i++){
        fr[i]=(fr[i-1]*i)%M;
        fi[i]=(fi[i-1]*modi(i))%M;
        //P(fr[i])
    }
}

