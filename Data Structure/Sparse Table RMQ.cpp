/**
    Name : Sparse table(RMQ)
    Description : Find min/max
    Time Complexity : Build O(nlogn) Query O(1)
*/
#include <bits/stdc++.h>
using namespace std;
//0 Indexed
#define MX 10000
int spt[MX][22];
int n,ar[MX]={ 7, 2, 3, 0, 5, 10, 3, 12, 18 };
void buildST()
{
	for (int i = 0; i < n; i++) spt[i][0] = ar[i];

	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 0; (i + (1 << j) - 1) < n; i++) {
            spt[i][j] = min(spt[i + (1 << (j - 1))][j - 1] , spt[i][j - 1]);
		}
	}
}

int query(int l, int r)
{
    if(l>r) return INT_MAX;
	int j = (int)log2(r - l + 1);
	///j = 31 - __builtin_clz(r - l+1);
	return min (spt[l][j], spt[r - (1 << j) + 1][j]);
}

// Driver program
int main()
{

    n = 9;
	buildST();
	cout << query(4, 7) << endl;
	cout << query(7, 8) << endl;
	return 0;
}
