///   *** Quick Sort  [nlogn]

ll partition(ll ara[],int lw,int hi){
    ll pivot = ara[hi],i,j;
    for(i=lw,j=lw;j<=hi;j++){
        if(ara[j]<pivot){
            swap(ara[i++],ara[j]);
        }
    }
    swap(ara[i],ara[hi]);
    return i;
}


void Quicksort(ll ara[],ll lw,ll hi){
    if(lw>=hi) return;
    ll pivot = partition(ara,lw,hi);
    Quicksort(ara,lw,pivot-1);
    Quicksort(ara,pivot+1,hi);
}