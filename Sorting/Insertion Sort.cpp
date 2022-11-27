
///  *** Insertion Sort  [n*n]

void insertionSort(ll ara[],ll n){
    ll i,j,tmp;
    for(i = 1; i<=n; i++){
        tmp = ara[i];
        j = i-1;
        while(j >= 1 && ara[j] > tmp){
            ara[j+1] = ara[j];
            j--;
        }
        ara[j+1] = tmp;
    }
}
