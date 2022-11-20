
/// *** Squre Root Decomposition [Sqrt(n)*Query]

/** 1 based indexing
*   if index are 1 2 3 4 5 6 7 and block size is 3 then
*   1 2 is first block and 3 4 5 is in second block
*   this will reduce coding complexity
*/

int ara[MX],block[sqqrt(MX)],rt,in=0;

void update(){
    /// point update is simple
    /// segment update is like query
}

void creat(int n){
    in=0;
    int mn = INT_MAX,i;
    for(i=1;i<n;i++){
        mn = min(ara[i],mn);
        if(i%rt==0){
            block[++in] = mn;
            mn = INT_MAX;
        }
    }
    block[++in] = mn;
}

int query(int l,int r){
    int mn = ara[l];

    while(l%rt!=0&&l<=r&&l!=1){
        mn = min(ara[l],mn);
        l++;
    }
    while(l+rt<=r){
        l += rt;
        mn = min(mn,block[l/rt]);
    }
    while(l<=r){
        mn = min(ara[l],mn);
        l++;
    }
    return mn;
}
