
/// *** BitwiseSieve  [~ n log(n) may be ]
///  [It can be use for finding huge number of primes]~10^8

#define check(X) (mkr[X>>6]&(1<<((X&63)>>1)))
#define mark(X) mkr[X>>6]|=(1<<((X&63)>>1))
int mkr[10000900/64],SZ=10000020,pr[700000],in=0;

void bitwsiv()
{
    int i,j,rt=sqrt(SZ)+1;
    for(i=3; i<=rt; i+=2){
        if(!check(i)){
            for(j=i*i; j<=SZ; j+=i+i){
                mark(j);
            }
        }
    }
    pr[++in]=2;
    for(i=3; i<=SZ; i+=2){
        if(!check(i))pr[++in]=i;
    }
}

