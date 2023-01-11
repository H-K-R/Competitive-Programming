/**
    Name : Bipartite Matching
    Description : Find maximum matching. we can find bipartite graph from left or right array
                  lt = left, rt =right, ed = adjesency matrix
                  left and right graph can contains nodes with same same or number
    Time Complexity : O(EV)
    Some Properties :
        * in a graph if we push both side then number of pair is ceil(Bipartite/2)
        * A graph is bipartite, if it doesn't contain any odd cycle.
        0. V = A u B
        1. Konigs minimax: In a bipartite graph v = t and a = p
        2. Hall's theorem: G has a matching from A to B, iif, for all X (subset of A), |adj(X)| >= |X|
        3. The Marriage Theorem: A perfect match exist iff, it has a matching from A to B and |A| = |B|
        4. Dilworth Theorem: For a finite partially ordered poset S,
        the largest antichain is equal to the minimum chain partition and vice versa.
        Consider a bipartite graph built this way, A = S, B = S and and edge from x(A) to y(B) exists if x <= y.
        Let, c be the minimum chain partition. Then, v + c = n.
*/


#define MX 55
vector<int>ed[MX];
int lt[MX],rt[MX];
bool vs[MX];

bool bpm(int u){
    int i,v;
    for(i=0;i<ed[u].size();i++){
        v = ed[u][i];
        if(vs[v]) continue;
        vs[v] = 1;
        if(rt[v]==-1||bpm(rt[v])){
            rt[v] = u;
            lt[u] = v;
            return 1;
        }
    }
    return 0;
}
// n = size of left set
int bipartiteMatching(int n){
    memset(lt,-1,sizeof lt);
    memset(rt,-1,sizeof rt);
    int mxBpm=0,i;
    for(i=1;i<=n;i++){
        memset(vs,0,sizeof vs);
        if(bpm(i)) mxBpm++;
    }
    return mxBpm;
}

// clear edge
ed[i].push_back(j) // i may same as j
