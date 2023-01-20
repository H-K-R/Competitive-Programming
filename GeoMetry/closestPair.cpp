/**
	Given N distinct points in
	Euclidean 2D space, compute
    the minimum (squared) distance
    between any two distinct points.
*/
#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1.0)
#define EPS 1e-9

typedef long long T;

struct PT{
	T x,y;
	PT() {}
	PT(T x, T y): x(x),y(y) {}
	
	PT operator+(PT p) {return {x+p.x, y+p.y};}
	PT operator-(PT p) {return {x-p.x, y-p.y};}
	PT operator*(T d) {return {x*d, y*d};}
	PT operator/(T d) {return {x/d, y/d};}
};
bool operator<(PT p1, PT p2)
{
    if(fabs(p1.x-p2.x)<EPS)
        return p1.y<p2.y;
    return p1.x<p2.x;
} 
T dis2(PT a, PT b){
	a=a-b;
	return a.x*a.x+a.y*a.y;
}

T ClosestPair(vector<PT> p){
	T n=p.size();
	sort(p.begin(), p.end());
	set< PT > s; //store {y,x}

	T mn2=4e18,mn=2e9;
	for(int i=0,j=0; i<n; i++)
	{
		mn=1+sqrt(mn2);
		while(p[i].x-p[j].x>=mn2){
			s.erase({p[j].y,p[j].x});
			j++;
		}

		auto it1=s.lower_bound({p[i].y-mn, p[i].x});
		auto it2=s.lower_bound({p[i].y+mn, p[i].x});

		swap(p[i].x,p[i].y);
		for(auto it=it1; it!=it2; it++){
			PT temp=(*it);
			mn2=min(mn2, dis2(p[i],temp));
		}

		s.insert(p[i]);
	}

	return mn2;
}

int main()
{
	T n,i,x,y;
	vector<PT> v;

	cin>>n;
	for(i=0; i<n; i++)
	{
		cin>>x>>y;
		v.push_back({x,y});
	}
	cout<<ClosestPair(v)<<endl;
}
