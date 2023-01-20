#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
struct point
{
    ll x,y;
};
struct cmp_x 
{
    bool operator()(const point & a, const point & b) const 
    {
        return a.x > b.x || (a.x == b.x && a.y > b.y);
    }
};
struct cmp_y 
{
    bool operator()(const point & a, const point & b) const
    {
        return a.y > b.y;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;
    vector<point> arr(n);
    ll a=0,b=0;
    for(int i=0;i<n;i++)
    {
        cin >> a >> b;
        point k;
        k.x=a;
        k.y=b;
        arr[i]=k;
    }
    sort(arr.begin(),arr.end(),cmp_x());
    sort(arr.begin(),arr.end(),cmp_y());
    /*for(auto p : arr)
        cout<<p.x<<" "<<p.y<<endl;*/
    ll ans=LLONG_MAX;
    if(n<=100)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                ll dis=((arr[i].x-arr[j].x)*(arr[i].x-arr[j].x)) + ((arr[i].y-arr[j].y)*(arr[i].y-arr[j].y));
                ans=min(ans,dis);
            }
        }
    }
    else
    {
    for(int i=1;i<n;i++)
    {
        ll dis=((arr[i].x-arr[i-1].x)*(arr[i].x-arr[i-1].x)) + ((arr[i].y-arr[i-1].y)*(arr[i].y-arr[i-1].y));
        ans=min(ans,dis);
    }}
    cout << ans << "\n";
    return 0;
}
