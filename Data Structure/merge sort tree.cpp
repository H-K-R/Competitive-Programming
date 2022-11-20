///   *** Merge Sort Tree [nlog(n) + query*log(n)*log(n)]


int ara[MX];
vector<int>seg[MX*4];
/// 1 based index

int bns(int n,int val){
    /// lower bound 1 2 2 2 3 4
    /// then returns 2
    int mid,i,j,low=0,high = seg[n].size()-1;
    while((high-low)>4){
        mid = (low+high)/2;
        if(seg[n][mid]<=val) low = mid;
        else high = mid - 1;
    }
    for(low;low<=high&&low<seg[n].size();low++){
        if(seg[n][low]>val) break;
    }
    return seg[n].size()-low; /// numbers greater than value
}

void mergee(int x,int y,int z){ /// merging 2 vector x and y to Z in sorted order
    int i,j,k,md,sz;
    sz = seg[x].size() + seg[y].size();
    for(i=0,j=0,k=0;k<sz;k++){
        if(i>=seg[x].size()) seg[z].push_back(seg[y][j++]);
        else if(j>=seg[y].size()) seg[z].push_back(seg[x][i++]);
        else if(seg[x][i]<seg[y][j]) seg[z].push_back(seg[x][i++]);
        else seg[z].push_back(seg[y][j++]);
    }
}

/** [low,high]  total range :: variable range
*   [qlow,qhigh] query range
*   pos = current position
*/
void creat(int low,int high,int pos){ /// creating merge sort tree
    if(low==high){
        seg[pos].push_back(ara[low]);
        return ;
    }
    int mid = (low+high)/2;
    creat(low,mid,pos*2);
    creat(mid+1,high,pos*2+1);
    mergee(pos*2,pos*2+1,pos);
    /// merge with stl
    /// merge(seg[pos*2].begin() , seg[pos*2].end(), seg[pos*2].begin(), seg[pos*2].end(),back_inserter(seg[pos]));
}

int query(int low,int high,int qlow,int qhigh,int pos,int val){
    if(qlow>qhigh) return 0;
    if(qlow>high||qhigh<low) return 0;
    if(qlow<=low&&qhigh>=high){
        return bns(pos,val);
    }
    int mid = (low + high)/2;
    return query(low,mid,qlow,qhigh,pos*2,val) + query(mid+1,high,qlow,qhigh,pos*2+1,val);
}

/// *** For Rnage orders statistics (find k'th number in sorted segment)

vector<pii>input;
vector<int>seg[MX*4];

void creat(int low,int high,int pos){ /// creating merge sort tree
    if(low==high){
        seg[pos].push_back(input[low-1].second); /// in is 0 based
        return ;
    }
    int mid = (low+high)/2;
    creat(low,mid,pos*2);
    creat(mid+1,high,pos*2+1);
    mergee(pos*2,pos*2+1,pos);
}

/** calculating total number in left range lower than the given index
*  if numbers are greater than equals to the searging value than look into left
*  searhing on right sub array and substracting left sub arrys given up values
*/

int query(int low,int high,int qlow,int qhigh,int pos,int val)
{
    if(low==high) return seg[pos][0];
    int mid = (low+high)>>1,left=pos<<1;

    int total = upper_bound(seg[left].begin(),seg[left].end(),qhigh) -
    lower_bound(seg[left].begin(),seg[left].end(),qlow);

    if(total>=val){
        return query(low,mid,qlow,qhigh,pos*2,val);
    }
    else{
        return query(mid+1,high,qlow,qhigh,pos*2+1,val-total);
    }
}

sort(input.begin(),input.end());




