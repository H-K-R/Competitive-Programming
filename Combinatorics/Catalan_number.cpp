
/**
    Name : Catalan Number
    n’th catalan number : Cn = (1/(n+1))(2n n) = (2n n) - (2n n+1)
                =(2n)!/((2n-n)!*n!*(n+1))
                =(2n)!/((n)!*(n+1)!)

    C(0) = C(1) = 1
    C(4) = C0*C3 + C1*C2 + C2*C1 + C3*C0
    C(n) =C(0)*(n-1) +C(1)*C(n-2) +.......... +C(i)*C(n-i-1)+........+C(n-1)*C(0)

    * the number of ways a polygon with n+2 sides can be cut into triangles
    * the number of ways to use n rectangles to tile a stairstep shape (1, 2, ..., n−1, n).
    * Cn counts the number of expressions containing n pairs of parentheses which are correctly matched
    * Cn is the number of different ways (n + 1) factors can be completely parenthesized  catalan(3) = 5 , ex :  ((ab)c)d,   (a(bc))d ,   (ab)(cd) ,   a((bc)d) ,   a(b(cd))
    * Count the number of possible Binary Search Trees with n keys
    * Total number of full binary tree : catalan(n) * factorial(n)
    * the number of paths of length 2n through an n-by-n grid that do not rise above the main diagonal
    * Cn is the number of ways to form a “mountain ranges” with n upstrokes and n down-strokes that all stay above the original line.The mountain range interpretation is that the mountains will never go below the horizontal.
    * Cn is the number of ways that the vertices of a convex 2n-gon can be paired so that the line segments joining paired vertices do not intersect. This is precisely the condition that guarantees that the paired edges can be identified (sewn together) to form a closed surface of genus zero (a topological 2-sphere).

*/

///Time Complexity =~ onetime n for factorial
/// and in each query [log(n)]

#define ll long long
#define MX 1000005
#define MD 100000007

ll powr(ll n, ll p){
    if(p==0) return 1;
    if(p==1) return n;
    if(p&1LL) return (powr(n,p-1)*n)%MD;
    else{
        ll x = powr(n,p/2)%MD;
        return (x*x)%MD;
    }
}

ll inverse(ll n){
    return (powr(n,MD-2))%MD;
}

ll ft[MX];

void fact(){
    ll i;
    ft[0] = 1;
    for(i=1;i<MX;i++){
        ft[i] = (ft[i-1]*i)%MD;
    }
}

ll nCr(ll n,ll r){
    ll x = ft[n];
    ll y = inverse((ft[r]*ft[n-r])%MD)%MD;
    return (x*y)%MD;
}

ll catalan(ll n){
    ll  x = nCr(2*n,n);
    return (x*inverse((n+1)))%MD;
}
