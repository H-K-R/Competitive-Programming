#include<bits/stdc++.h>
#define MAX 50004
#define ll long long
using namespace std;

ll power[MAX];
ll p = 153LL;
ll M = 1000000009LL;
ll pre[MAX];

void init()
{
    power[0]=1LL;
    for(int i=1; i<MAX; i++)
        power[i]=(power[i-1]*p)%M;
}

ll BigMod(ll n,ll p,ll MOD)
{
    ll temp;
    if(p==0)
        return 1;
     temp=BigMod(n,p/2,MOD);
     temp=(temp*temp)%MOD;
    if(p&1)
        temp=(temp*n)%MOD;
    return temp;
}

ll inv(ll n, ll MOD)
{
	return BigMod(n, MOD-2, MOD);
}
ll get_hash(string s)
{
    pre[0]=0;
    for(int i=0; i<s.size(); i++)
        pre[i+1]=(M+pre[i]+((ll)s[i])*power[i+1])%M;
    return pre[s.size()];
}

ll sub_hash(int i, int j)
{
    ll x = ((pre[j]-pre[i-1])*inv(power[i-1], M))%M;
    while(x<0)
        x+=M;
    return x;
}


int main()
{
    init();
    int i,j;
    string s,t;
    cin>>s>>t;
    ll need = get_hash(t);
    get_hash(s);

    for(i=0; i+t.size()<=s.size(); i++)
    {
        if(sub_hash(i+1, i+t.size())==need)
            cout<<i<<" ";
    }
    return 0;
}

/**
ababbababa
aba
*/
