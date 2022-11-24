/**
*   Name : Totient Function
*   Description : Find number of co-prime of a number less than that number
*	Complexity : O(sqrt(n))
*   source : https://cp-algorithms.com/algebra/phi-function.html
*/

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}
