///  *** BFS [ total(node + edge) ]
/// level by level travarse

vector <int> ed[MX];
int lev[MX],ms,par[MX];
bool vs[MX];
int bfs(int s){
    int i,j,d,f,v;
    queue <int> q;
    q.push(s);
    lev[s]=0;
    vs[s]=1;
    while(!q.empty()){
        f=q.front();
        q.pop();
        for(i=0;i<ed[f].size();i++){
            v=ed[f][i];
            if(!vs[v]){
                vs[v]=1;
                q.push(v);
                lev[v]=lev[f]+1;
            }
        }
    }
    return lev[destinition];
}

