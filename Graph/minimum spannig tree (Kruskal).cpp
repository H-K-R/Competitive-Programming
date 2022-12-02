/// *** Minimum Spanning Tree :: Kruskal [mlogm+m]

struct edge{
    int u,v,w;
    bool operator < (const edge& x)const {
        return w>x.w;
    }
}ab;

int ara[105],n;
vector<edge>vc;
/// vc.push_back(ab) make edge and push

int find(int n){
    if(ara[n] == n) return n;
    return ara[n] = find(ara[n]);
}

int mst()
{
    int sum=0,i,u,v,cn=0,mn=INT_MAX;
    for(i=0;i<=102;i++) ara[i] = i;
    sort(vc.begin(),vc.end());
    for(i=0;i<vc.size();i++){
        u = find(vc[i].u);
        v = find(vc[i].v);
        if(u!=v){
            ara[v] = u;
            sum+=vc[i].w;
            cn++;
            //mn = min(mn,vc[i].w);
            if(cn==n) break;
        }
    }
    return sum;
}

