
/// *** Normal Sieve [ n*sqrt(n) ]
///   [ mark can be check for is prime ]

#define SZ 100009
int pr[78600],in=0;
bool mr[SZ+3];

void sieve(){
    int i,j,sq,p;
    sq=sqrt(SZ)+2;
    mr[1]=1;
    for(i=2; i<sq; i++){
        if(!mr[i]){
            for(j=i*i;j<=SZ;j+=i){
                mr[j]=1;
            }
        }
    }
    for(i=2; i<SZ; i++){
        if(!mr[i]){
            pr[++in] = i;
        }
    }
}

/// *** Efficient Sieve [ n*log(n)~]
///   [mr array can't be use for prime check || Odd numbers only]

#define SZ 1000009
int pr[78600],in=0;
bool mr[SZ+3];

void sieve(){
    int i,j,sq,p;
    sq=sqrt(SZ)+2;
    for(i=3; i<sq; i+=2){
        if(!mr[i]){
            for(j=i*i; j<=SZ; j+=i<<1){
                mr[j]=1;
            }
        }
    }
    pr[++in] = 2;
    for(i=3; i<SZ; i+=2){
        if(!mr[i]){
            pr[++in] = i;
        }
    }
}

