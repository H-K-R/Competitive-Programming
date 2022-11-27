
///  *** Selection sort  [n*n]

void selectionSort(ll ara[],ll n){
    for(int i = 1; i<=n; i++){
        for(int j = i+1; j<=n; j++){
            if(ara[i]>ara[j]){
                swap(ara[i],ara[j]);
            }
        }
    }
}