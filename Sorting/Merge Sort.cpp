///   *** merge sort  [nlog(n)]

#define MX 1000000

ll tmp[MX];

void mergeSort(ll ara[],ll l,ll r){
    if(l==r) return;
    ll i,j,k,md;
    md = (l+r)/2;
    mergeSort(ara,l,md);
    mergeSort(ara,md+1,r);
    for(i=l,j=md+1,k=l;k<=r;k++){
        if(i>md) tmp[k] = ara[j++];
        else if(j>r) tmp[k] = ara[i++];
        else if(ara[i]<ara[j]) tmp[k] = ara[i++];
        else tmp[k] = ara[j++];
    }
    for(i=l;i<=r;i++){
        ara[i] = tmp[i];
    }
}
