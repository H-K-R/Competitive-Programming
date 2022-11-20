
///   *** BIT O(Log(n)) space O(n)

/**   1 based index
*     which functions has inverse function that can be solve bye BIT
*     it works like consucative sums but in log(n)
*/

int n=SIZE; //of space;
void update(int idx,int val)//adding value val to idx index
{
    while(idx<=n){
        bitree[idx]+=val;
        idx+=idx&(-idx); // Last set of digit
    }
}
int query(int idx){// returns sum of [1,idx] index
    int sum=0;
    while(idx>0){
        sum+=bitree[idx];
        idx-=idx&(-idx);
    }
    return sum;
}
