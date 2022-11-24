/**  Gaussian Elemination 
     Complexity : O(n^3)
     solve equations with any degree   
*/

void gauss(){
    for(i=0;i<n;i++){
        l = i;
        for(j=i+1;j<n;j++){
            if(abs(ara[j][i])>abs(ara[l][i])){
                l = j;
            }
        }
        if(i!=l){
            for(j=0;j<=n;j++){
                swap(ara[i][j], ara[l][j]);
            }
        }
        for(j=0;j<n;j++){
            if(j!=i){
                tmp = ara[j][i]/ara[i][i];
                for(k=i;k<=n;k++){
                    ara[j][k] -= tmp*ara[i][k];
                }
            }
        }
    }
    for(i=0;i<n;i++){
        ara[i][n] /= ara[i][i]; ///final result
    }
}
