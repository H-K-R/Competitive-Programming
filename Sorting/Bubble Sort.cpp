///  *** Bubble sort [n*n]

void bubbleSort(ll ara[],ll n){
    ll i,j;
    for(i = 1; i <= n; i++){
        for(j = 1; j < n-i; j++){
            if(ara[j+1] < ara[j]){
                swap(ara[j+1],ara[j]);
            }
        }
    }
}