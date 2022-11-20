/// *** Segment Tree [log(total array size)*Query]

/** [ulow,uhigh] Query Range
*   [low,high] total range of root
*   [qlow,qhigh] Query Range
*   Currrent position = pos
*   0 based Index And Root is also 0
*/

int ara[MX],seg[4*MX],lazy[4*MX];

void creat(int low,int high,int pos)
{
    if(low==high){
        seg[pos] = ara[low]; // reached leaf and update
        return ;
    }
    int mid = (high+low)/2;
    creat(low,mid,pos*2+1);
    creat(mid+1,high,pos*2+2);
    seg[pos] += seg[pos*2+1] + seg[pos*2+2];
}

void update(int low,int high,int ulow,int uhigh,int val,int pos)
{
    if(low>high) return ;
    if(lazy[pos]!=0){ /// is not propagated yet
        seg[pos] += (high-low+1)*lazy[pos];
        if(low!=high){  ///if not leaf node
            lazy[pos*2+1] += lazy[pos];
            lazy[pos*2+2] += lazy[pos];
        }
        lazy[pos] = 0;
    }

    if(ulow>high||uhigh<low) return; ///No overlap
    if(ulow<=low&&uhigh>=high){ /// Total Overlap
        seg[pos] += (high-low+1)*val;
        if(low!=high){
            lazy[pos*2+1] += val;
            lazy[pos*2+2] += val;
        }
        return;
    }
    /// Partial overlap
    int mid = (high+low)/2;

    update(low,mid,ulow,uhigh,val,pos*2+1);
    update(mid+1,high,ulow,uhigh,val,pos*2+2);
    seg[pos] = seg[pos*2+1] + seg[pos*2+2]; /// Updating the intermediate node
}

int query(int low,int high,int qlow,int qhigh,int pos)
{
    if(low>high) return 0;
    if(lazy[pos]!=0){
        seg[pos] += (high-low+1)*lazy[pos];
        if(low!=high){
            lazy[pos*2+1] += lazy[pos];
            lazy[pos*2+2] += lazy[pos];
        }
        lazy[pos] = 0;
    }

    if(qlow>high||qhigh<low) return 0;

    if(qlow<=low&&qhigh>=high)
        return seg[pos];

    int mid = (high+low)/2;

    return query(low,mid,qlow,qhigh,pos*2+1) + query(mid+1,high,qlow,qhigh,pos*2+2);
}

