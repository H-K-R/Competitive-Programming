/**
    Name : Sieve O(n)
    Description : pr stores all primes and lp stores lowest prime factors
    Complexity : O(n)
*/

const int N = 10000000;
int lp[N+1];
vector<int> pr;

void sieve(){
    int i,j;
    for (i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i*pr[j]] = pr[j];
    }
}
