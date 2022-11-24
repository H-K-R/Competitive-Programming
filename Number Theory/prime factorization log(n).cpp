/**
    Description : prime factorization
    Complexity : O(log n)
    Limitation : memory complexity O(n) so it works up to 10^7
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

vector<int> prime_fact(int n){
    vector<int> pf;
    while (n != 1){
        pf.push_back(lp[n]);
        n = n / lp[n];
    }
    return pf;
}
