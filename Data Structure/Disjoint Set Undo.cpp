/**
 * Name : Dijoint Set with undo
 * Description : DisjointSet (Makes a set of sets, merge sets, set membership, no. of sets, undo last operation,size of each component)
 * Time Complexity : parent O(lg(N)), setUp O(lg(N)), undo O(1),
 */

#define MX 10000
int rp[MX],sz[MX];
int compo;
int pts[MX*2],in=0;

int parent(int n){
    if(rp[n]==n)return n;
    return rp[n]=parent(rp[n]);
}

// additionally storing parent which is connected to another parents
void setUp(int a,int b){
    a = parent(a);
    b = parent(b);
    if(a==b){
        pts[++in]=-1;
        return;
    }
    if(sz[a]<sz[b]){
        rp[a] = rp[b];
        sz[b] += sz[a];
        pts[++in]=a;
    }
    else{
        rp[b] = rp[a];
        sz[a] += sz[b];
        pts[++in] = b;;
    }
    compo--;
}

void undo(){
    if(!in) return;
    int n = pts[in--];
    if(n!=-1) {
        sz[parent(rp[n])] -= sz[n];
        rp[n]=n;
        compo++;
    }
}

void init(int n){
    in=0;
    for(int i=0;i<=MX;i++){
        rp[i]=i;
        sz[i]=1;
    }
    compo=n;
}
