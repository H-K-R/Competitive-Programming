/**
    Name : Chinese remainder theorem

    Description : lets think about an equation:   x % num[i] = rem[i];
    Given num[] and rem[] list, you have to calculate an x ,
    so that for every index i, corrsponding num[i] and rem[i] should satisfy the equation;
*/


ll num[15], rem[15], n;

pll extnuc(ll a,ll b)
{
    if(b==0)return pll(1,0);
    pll d=extnuc(b,a%b);
    return pll(d.second,d.first-d.second*(a/b));
}

ll modi(ll n, ll M)
{
    pll d=extnuc(n,M);
    return ((d.first%M)+M)%M;
}

ll chinese_remainder(int k)
{
    ll prod = 1;

    for(int i = 0; i < k; ++i)
        prod *= num[i];

    ll res = 0;

    for(int i = 0; i < k; ++i) {
        ll pp = prod / num[i];

        int inv = modi(pp, num[i]);
        if(inv<0) inv += num[i];

        res += rem[i] * pp * inv;
        res %= prod;
    }
    return res;
}

int main()
{
    scanf("%lld", &n);
    for(i=0;i<n;i++)scanf("%lld %lld", &num[i], &rem[i]);
    printf("Case %d: %lld\n", ++tc, chinese_remainder(n));
    return 0;
}
