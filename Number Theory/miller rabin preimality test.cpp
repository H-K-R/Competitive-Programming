
/// ***Miller-Rabin Primality test [120]

/** usigned long long is not working sometimes
*   left shift == mult by 2 right shift == divide bye 2
*   multiplying two numbers (a*b)%c avoiding overflow
*/
ll mulmod(ll a, ll b, ll mod){
    ll x = 0,y = a % mod;
    while (b > 0){
        if (b&1) x = (x + y) % mod;
        y = (y<<1) % mod;
        b >>= 1;
    }
    return x % mod;
}

//Bigmod
ll modulo(ll n, ll r, ll mod){
    ll x = 1;
    while (r > 0){
        if (r&1) x = mulmod(x,n,mod);
        n = mulmod(n,n,mod);
        r >>= 1;
    }
    return x % mod;
}
/// higher value of "it" ensure higher percision [recomendation 7]

bool MillerRabin(ll p,int it)
{
    if (p < 2) return 0;
    if (p != 2 && p % 2==0) return 0;

    ll i,a,tmp,mod,s=p-1;

    while(s%2==0){
        s>>=1;
    }
    for(i=0;i<it;i++){
        a = rand()%(p-1)+1;
        tmp = s;
        mod = modulo(a, tmp, p);
        if(mod==1 || mod == p-1)continue;
        while (tmp!=p-1&&mod!=1&&mod!=p-1){
            mod = mulmod(mod, mod, p);
            tmp <<= 1;
        }
        if(mod!=p-1) return 0;
    }
    return 1;
}

/** this body of miller rabin giving correct ans upto 10^9
*   with lower time complexity
*/

for(i=1;i<=it;i++){
    a = rand() % (p - 1) + 1, tmp = s;
    mod = mod_pow(a, tmp, p);
    while(tmp != p - 1 && mod != 1 && mod != p - 1) {
        mod = mod_mul(mod, mod, p);
        tmp *= 2;
    }
    if (mod != p - 1 && tmp % 2 == 0) return false;
}

