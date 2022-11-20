/**
	Description : Efficient and easy segment trees , Range [l, r)
	Time Complexity : O(logn)	
	from: https://codeforces.com/blog/entry/18051
*/

const int N = 1e5;  // limit for array size
int n;  // array size
int tr[2 * N];
void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) tr[i] = tr[i<<1] + tr[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
  for (tr[p += n] = value; p > 1; p >>= 1) tr[p>>1] = tr[p] + tr[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += tr[l++];
    if (r&1) res += tr[--r];
  }
  return res;
}

int main() {
  //scanf("%d", &n);
  int ar[]={1,3,4,5,4,5,6,4,6,4,5,6,6,5};
  n=5;
  for (int i = 0; i < n; ++i) {
    tr[n+i]=ar[i];
  }
  build();
  printf("%d\n", query(0, 4));//that means [0,3]
  printf("%d\n", query(2, 3));
  modify(0, 5);
  printf("%d\n", query(0, 4));
  return 0;
}
