/**
    Description : BIT range update range query
    Time Complexity : all log(n)
*/

/// Remember to use 1 based indexing
//const int MX = 100005;

ll query(ll *bit, int indx)
{
    ll sum = 0;
    while (indx) {
        sum += bit[indx];
        indx -= (indx & -indx);
    }
    return sum;
}

void update(ll *bit, int indx, ll x)
{
    while (indx < MX) {
        bit[indx] += x;
        indx += (indx & -indx);
    }
}
ll B1[MX],B2[MX];//set 0

void Rupdate(int l, int r, ll v){
    update(B1, l, v);
    update(B1, r+1, -v);
    update(B2, l, -((l-1)*v));
    update(B2, r+1, r*v);
}
ll Rquery1(int p){
    ll b1,b2;
    b1 = query(B1, p);
    b2 = query(B2, p);
    return b1 * p + b2;
}
ll Requery(int l,int r){
    return Rquery1(r)-Rquery1(l-1);
}
