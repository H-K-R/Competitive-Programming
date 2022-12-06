/// *** DFS [E+V]

vector<int>ed[MX];
bool vs[MX];
int lev[MX];

void dfs(int n)
{
    if(vs[n]) return;
    vs[n] = 1;
    int i,v;
    for(i=0;i<ed[n].size();i++){
        v = ed[n][i];
        dfs(v);
    }
}
