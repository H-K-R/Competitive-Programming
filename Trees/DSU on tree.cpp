#include <bits/stdc++.h>
#define ll long long
#define P(X) cout<<"db "<<X<<endl;
#define P2(X,Y) cout<<"db2 "<<X<<" "<<Y<<endl;
#define rep(i,n) for(i=1;i<=n;i++)
#define FO freopen("t.txt","w",stdout);
#define MS(XX,YY) memset(XX,YY,sizeof(XX));
#define pii pair<int,int>
#define chk(n,i) (bool)(n&(1<<i))
#define on(n,i) (n|(1<<i))
#define off(n,i) n=n&(~(1<<i))
#define eps 10e-7
#define MX 1000005
using namespace std;

/**
*  Description : Useful for all same types of operations on each node on a tree
*               cnt[] storing all number of color of a type in sub tree of v
*               res[] storing sum of color which apears maximum numbers of time
*
*  Time complexity : O(nlogn)
*  Source :https://codeforces.com/blog/entry/44351
*/


vector<int>g[MX];

int sz[MX];
void getsz(int v, int p){
    sz[v] = 1;  // every vertex has itself in its subtree
    for(auto u : g[v])
        if(u != p){
            getsz(u, v);
            sz[v] += sz[u]; // add size of child u to its parent(v)
        }
}

ll cnt[MX],col[MX],ans[MX],res[MX],mxn;
bool big[MX];

void add(int v, int p, int x){
    //ans[cnt[col[v]]] -= col[v];
    cnt[col[v]] += x;
    //ans[cnt[col[v]]] += col[v];
    //mxn = max(cnt[col[v]],mxn);
    for(auto u: g[v])
        if(u != p && !big[u])
            add(u, v, x);
}


void dfs(int v, int p, bool keep){
    int mx = -1, bigChild = -1;
    for(auto u : g[v])
       if(u != p && sz[u] > mx)
          mx = sz[u], bigChild = u;
    //run a dfs on small childs and clear them from cnt
    for(auto u : g[v])
        if(u != p && u != bigChild)
            dfs(u, v, 0);  //
    // actual processing of vertex v starts from here
    //mxn = 0;
    if(bigChild != -1)
        dfs(bigChild, v, 1), big[bigChild] = 1;  // bigChild marked as big and not cleared from cnt
    // calculating ans
    add(v, p, 1);
    //res[v] = ans[mxn];
    /** here access the result for each node. if needed then access on add() function
        now cnt[c] is the number of vertices in subtree of vertex v that has color c.
        You can answer the queries easily.
    */
    if(bigChild != -1)
        big[bigChild] = 0;
    if(keep == 0)
        add(v, p, -1);
}



int main()
{
    ll i,j,a,b,ts,cn=0,cas=0,n,m,x,y,sum=0,mn=INT_MAX,u,v;
    //freopen("test.txt","r",stdin);
    cin>>n;
    for(int i = 1; i <= n; i++) {
		cin >> col[i];
	}
    for(i=1;i<n;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    getsz(1,0);
    dfs(1,0,1);
    for(int i = 1; i <= n; i++) {
		cout << res[i] << ' ';
	}
    return 0;
}
