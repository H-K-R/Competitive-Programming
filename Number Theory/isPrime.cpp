/** @return if "n" is prime then return true otherwise false
*   O(sqrt(n))
*/

int isprime(int n){
    if(n==2)return 1;
    if(!(n%2)||n<2)return 0;
    int i,sq=sqrt(n)+2;
    for(i=3; i<sq; i+=2)if(!(n%i))return 0;
    return 1;
}
