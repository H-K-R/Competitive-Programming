///nLog(n)
#include<bits/stdc++.h>
using namespace std;

string s,t;

vector<int> build_suffix_array(string s)
{
    int alphabet=256; //considering any character
    int n=(int)s.size();
    int i,k,cls;

    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    vector<int> ptmp(n), ctmp(n);

    pair<int, int> cur, prev;

    for(i=0; i<n; ++i)
        cnt[s[i]]++;
    for(i=1; i<alphabet; i++)
        cnt[i]+=cnt[i-1];
    for(i=0; i<n; i++)
        p[--cnt[s[i]]]=i;

    
    c[p[0]]=0;
    cls=1;
    for(i=1; i<n; i++)
    {
        if(s[p[i]] != s[p[i-1]])
            cls++;
        c[p[i]]=cls-1;
    }
    
    for(k=0; (1<<k)<n; ++k)
    {
        for(i=0; i<n; ++i)
        {
            ptmp[i]=p[i]-(1<<k);
            if(ptmp[i]<0) ptmp[i]+=n;
        }
        fill(cnt.begin(), cnt.begin()+cls, 0);

        for(i=0; i<n; i++)
            cnt[c[ptmp[i]]]++;
        for(i=1; i<cls; i++)
            cnt[i]+=cnt[i-1];
        for(i=n-1; ~i; i--)
            p[--cnt[c[ptmp[i]]]]=ptmp[i];

        ctmp[p[0]]=0;
        cls=1;
        for(i=1; i<n; ++i)
        {
            cur={c[p[i]], c[(p[i]+(1<<k))%n]};
            prev={c[p[i-1]], c[(p[i-1]+(1<<k))%n]};

            if(cur!=prev)
                cls++;
            ctmp[p[i]]=cls-1;
        }
        c.swap(ctmp);
    }

    //print
    //for(i=0; i<n; i++)
      //  cout<<p[i]<<" "<<s.substr(p[i], n-p[i]-1)<<"\n";
    return p;
}

int isEqual(int x)
{
    int m=(int)t.size();
    for(int i=0; i<m; i++)
    {
        if(s[i+x]==t[i])
            continue;
        if(s[i+x]<t[i])
            return -1;
        else
            return 1;
    }
    return 0;
}

bool B_search(vector<int>& p)
{
    int low=0,x;
    int high=(int)p.size()-1;
    int mid;

    while(low<=high)
    {
        mid=(low+high)/2;
        x=isEqual(p[mid]);
        if(x==0) return 1;
        if(x<0)
            low=mid+1;
        else
            high=mid-1;

    }
    return 0;
}

int main()
{
    int n;
    cin>>s>>n;
    s+="$";
    vector<int> v=build_suffix_array(s);
    while(n--)
    {
        cin>>t;
        if(B_search(v))
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}
