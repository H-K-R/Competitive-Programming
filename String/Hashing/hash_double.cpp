#include<bits/stdc++.h>
using namespace std;
#define ll long long


/*
31,53,149,569,1021,1049,1297,
1553,1559,2017,2027,2069,2111,
900000221,900000253,1000000007,
1000000009,1000000123,1000004119,
1000050169,1000850243,2018331023,
2018331061,2018331097,2018331127
*/
#define MXN             1000+10
#define M1              2018331097
#define M2              1000004119
#define B1              1021
#define B2              2017

ll pow1[MXN] , pow2[MXN];
void pre(){
    pow1[0] = pow2[0] = 1;
    for(ll i = 1 ; i<MXN ; i++){
        pow1[i] = (pow1[i-1] * B1)%M1;
        pow2[i] = (pow2[i-1] * B2)%M2;
    }
}
struct DoubleHash{
    ll H1[MXN], H2[MXN];
    string keystring;

    DoubleHash(string &s){
        keystring=s;
        calculate(s);
    }
    int id(char ch){
        if('a'<=ch && ch<='z')
            return ch-'a'+1;
        return ch-'A'+27;
    }
    void calculate(string &str){
        ll n=str.size();
        H1[0]=H2[0]=0;
        for(ll i=1; i<=n; i++){
            H1[i]=(B1*H1[i-1]+id(str[i-1]))%M1;
            H2[i]=(B2*H2[i-1]+id(str[i-1]))%M2;
        }
    }
    pair<ll,ll> tempHash(string &str){
        ll n=str.size();
        ll h1=0, h2=0;
        for(ll i=1; i<=n; i++){
            h1=(B1*h1+id(str[i-1]))%M1;
            h2=(B2*h2+id(str[i-1]))%M2;
        }
        return {h1,h2};
    }
    //1 based
    ll getHash1(ll lft, ll rgt){
        ll len=rgt-lft+1;
        ll ret=(H1[rgt]-H1[lft-1]*pow1[len]%M1 + M1)%M1;
        return ret;
    }
    ll getHash2(ll lft , ll rgt){
        ll len=rgt-lft+1;
        ll ret=(H2[rgt]-H2[lft-1]*pow2[len]%M2 + M2)%M2;
        return ret;
    }
    pair<ll,ll> getHash(ll lft, ll rgt){
        //pre(): must be calculated
        return {getHash1(lft,rgt), getHash2(lft,rgt)};
    }
    ll cmpSub(ll l1, ll r1, ll l2, ll r2){
        ll len1=r1-l1+1;
        ll len2=r2-l2+1;

        ll low=0, high=min(len1,len2),mid;
        ll eql=0;

        while(low<=high)
        {
            mid=(low+high)/2;
            if(getHash(l1, l1+mid-1)==getHash(l2, l2+mid-1))
            {
                eql=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        if(eql == min(len1, len2))
        {
            if(len1==len2) return 0;//equal
            if(len1<len2) return -1;//small [l1...r1]
            return 1;
        }
        if(keystring[l1+eql-1]<keystring[l2+eql-1])
            return -1;
        return 1;
    }
};

///Find s in t.
int main()
{
    pre();

    string s,t;
    cin>>t>>s;

    DoubleHash hT(t);

    ll n = s.size();
    auto p = hT.tempHash(s);

    for(ll i=1; i+n-1<=t.size(); i++)
    {
        auto p2=hT.getHash(i, i+n-1);
        //cout<<i<<": ("<<p2.first<<","<<p2.second<<") ("<<p.first<<","<<p.second<<")\n";
        if(p2==p)
            cout<<i<<" ";
    }
    cout<<endl;

    cin>>n;
    while(n--)
    {
        ll l1,l2,r1,r2;
        cin>>l1>>r1>>l2>>r2;
        ll x=hT.cmpSub(l1, r1, l2, r2);
        if(x==0)
            cout<<"equal\n";
        else if(x==-1)
            cout<<"small "<<t.substr(l1-1, r1-l1+1)<<endl;
        else
            cout<<"big "<<t.substr(l1-1, r1-l1+1)<<endl;
    }

    return 0;
}
/*
abababaa aba
5
1 1 3 3
1 2 3 4
1 2 3 5
1 3 4 5
2 4 6 8
*/
