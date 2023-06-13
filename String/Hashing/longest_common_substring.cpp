/*
    https://codeforces.com/gym/100126/attachments/download/1321/20122013-tryenirovka-spbgu-b-15-heshi-ru.pdf
    Problem A: find Longest Common Substring from K(K<11) string
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);


/*
31,53,149,569,1021,1049,1297,
1553,1559,2017,2027,2069,2111,
900000221,900000253,1000000007,
1000000009,1000000123,1000004119,
1000050169,1000850243,2018331023,
2018331061,2018331097,2018331127
*/
#define MXN             100000+10
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

    DoubleHash(){}
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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash{
    int operator()(int x) const { return x ^ RANDOM; }
};

DoubleHash h[10];
//O(K*N)
string getLCS_M_len(ll m, ll k){
    int mask=(1<<k)-1;

    //unordered_map<ll,int> mp1(k);
    //unordered_map<ll,int> mp2(k);

    gp_hash_table<ll, int, chash> mp1;
    gp_hash_table<ll, int, chash> mp2;

    for(int i=0; i<k; i++)
    {
        int n=h[i].keystring.size();
        for(int j=1; j+m-1<=n; j++)
        {
            auto p=h[i].getHash(j, j+m-1);
            mp1[p.first]|=(1<<i);
            mp2[p.second]|=(1<<i);

            if(mp1[p.first]==mask && mp2[p.second]==mask)
                return h[i].keystring.substr(j-1,m);
        }
    }

    return "";
}
//KNLogN
string LCS(ll k, ll mnLen){
    string ans,tmp;
    ll l=0,r=mnLen,mid;

    while(l<=r)
    {
        mid=(l+r)/2;
        tmp=getLCS_M_len(mid, k);
        if(tmp.size()){
            ans=tmp;
            //cout<<"Ok? "<<mid<<": "<<ans<<endl;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }

    return ans;
}
void solve(){
    ll k,i,j,mnLen=LLONG_MAX;
    string s;

    cin>>k;
    for(i=0; i<k; i++)
    {
        cin>>s;
        h[i]=DoubleHash(s);
        mnLen=min(mnLen, (ll)s.size());
    }
    cout<<LCS(k, mnLen)<<endl;
}

int main()
{
    FAST;
    pre();

    freopen("substr.in","r", stdin);
    freopen("substr.out","w", stdout);
    
    int t=1;
    //cin>>t;
    for(int cs=1; cs<=t; cs++){
        //cout<<"Case "<<cs<<": ";
        solve();
    }
    return 0;
}
