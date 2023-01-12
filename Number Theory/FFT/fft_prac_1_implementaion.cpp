//https://vjudge.net/problem/SPOJ-POLYMUL

#include <bits/stdc++.h>
using namespace std;
#define ll long long  
 
using cd = complex<double>;
const double PI = acos(-1);
 
void fft(vector<cd> & a, bool invert)
{
    int n = a.size();
 
    for (int i = 1, j = 0; i < n; i++)
    {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
 
        if (i < j)
            swap(a[i], a[j]);
    }
 
    for (int len = 2; len <= n; len <<= 1) 
    {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) 
        {
            cd w(1);
            for (int j = 0; j < len / 2; j++)
            {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
 
    if (invert) 
    {
        for (cd & x : a)
            x /= n;
    }
}
void for_multiplying_two_long_numbers(vector<ll> &result)
{
    int carry = 0;
    int n=result.size();
    for (int i = 0; i < n; i++)
    {
        result[i] += carry;
        carry = result[i] / 10;
        result[i] %= 10;
    }
}
//O(nLogn)
vector<ll> multiply(vector<ll> const& a, vector<ll> const& b)
{
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);
 
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);
 
    vector<ll> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
 
    //for_multiplying_two_long_numbers(result);
    return result;
}
 
void print(vector<ll> &kalu, int sz)
{
    while(kalu.size()>sz) kalu.pop_back();
    //if(!kalu.size()) cout<<"0";
    for(int i=kalu.size()-1; ~i; i--)
        cout<<kalu[i]<<" \n"[i==0];
    //cout<<"\n";
}
int main()
{
    ll t,x,i,n;
    cin>>t;

    vector<ll> a,b;
    while(t--)
    {
        cin>>n;
        for(i=0; i<=n; i++)
        {
            cin>>x;
            a.push_back(x);
        }
        for(i=0; i<=n; i++)
        {
            cin>>x;
            b.push_back(x);
        }
 
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        
        auto res=multiply(a,b);
        
        print(res, 2*n+1);
 
        a.clear();b.clear();
    }
} 
