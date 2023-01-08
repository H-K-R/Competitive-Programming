///  *** Dijkstra O(edge * log (node))

struct node{
    int id,cost;
    node(){}
    node(int nid,int ncost)
    {
        id=nid;
        cost=ncost;
    }
    bool operator < (const node&x)const{
        return  cost>x.cost;
    }
};

vector <int> ed[MX],ec[MX];
int ds[MX];
void dxt(int s){
    priority_queue <node> q;
    q.push(node(s,0));
    ds[s]=0;
    node fn;
    int i,u,v;
    while(!q.empty()){
        fn=q.top();
        q.pop();
        u=fn.id;
        if(fn.cost!=ds[u])continue;
        for(i=0;i<ed[u].size();i++){
            v=ed[u][i];
            if(ds[v]>ds[u]+ec[u][i]){
                ds[v]=ds[u]+ec[u][i];
                q.push(node(v,ds[v]));
            }
        }
    }
}

