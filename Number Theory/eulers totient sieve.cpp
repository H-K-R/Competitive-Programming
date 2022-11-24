/// ***Eulers totients Sieve [n*n]
/// Number of Co-prime upto a number

bool mr[MX];
int pi[MX];

void phi(){
    int i,j;
    pi[1] = 1;
    for(i=2;i<MX;i++){
        if(!mr[i]){
            for(j=i;j<MX;j+=i){
                if(pi[j]==0) pi[j] = j;
                mr[j] = 1;
                pi[j] = pi[j]/i*(i-1);
            }
        }
    }
}

