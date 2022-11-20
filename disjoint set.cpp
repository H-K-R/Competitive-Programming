
/**
    Name : Disjoint set union find
    Description : Always check parent for size or anything
    Complexity : O(n) ~ O(log n) ~ O(1)
*/

#define MX 10000
int rp[MX],sz[MX];

int parent(int n){
    if(rp[n]==n)return n;
    return rp[n]=parent(rp[n]);
}

void setUp(int a,int b){
    a = parent(a);
    b = parent(b);
    if(a==b) return;
    if(sz[a]<sz[b]){
        rp[a] = rp[b];
        sz[b] += sz[a];
    }
    else{
        rp[b] = rp[a];
        sz[a] += sz[b];
    }
}

void init(){
    for(int i=0;i<=MX;i++)
        rp[i]=i,sz[i]=1;
}
